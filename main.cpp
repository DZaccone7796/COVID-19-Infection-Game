#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

    int mapHeight = 20, mapWidth = 20, currentBlock = 0;
    float blockHeight = 150, blockWidth = 150, sidewalkWidth = 60, intersection = 50;

    QApplication a(argc, argv);

    QGraphicsScene* map = new QGraphicsScene();

    vector<QGraphicsRectItem*> cityBlocks(mapHeight * mapWidth);
    vector<QGraphicsRectItem*> sidewalks(mapHeight * mapWidth);
    for (int i = 0; i < mapHeight * mapWidth; i++) {
        cityBlocks.at(i) = new QGraphicsRectItem();
        sidewalks.at(i) = new QGraphicsRectItem();
    }

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            sidewalks.at(currentBlock + j)->setRect((blockWidth + sidewalkWidth + intersection) * j, (blockHeight + sidewalkWidth + intersection) * i,
                                                    blockWidth + sidewalkWidth, blockHeight + sidewalkWidth);
            cityBlocks.at(currentBlock + j)->setRect(((blockWidth + sidewalkWidth + intersection) * j) + sidewalkWidth / 2, ((blockHeight + sidewalkWidth + intersection) * i) + sidewalkWidth / 2,
                                                     blockWidth, blockHeight);
            map->addItem(sidewalks.at(currentBlock + j));
            map->addItem(cityBlocks.at(currentBlock + j));
        }
        currentBlock += mapWidth;
    }

    QGraphicsView* view = new QGraphicsView(map);

    view->show();

    return a.exec();
}
