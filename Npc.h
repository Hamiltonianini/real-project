#ifndef NPC_H
#define NPC_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class NPC {
public:
    string name, mapNames;
    vector<string> messages;
    sf::Sprite sprite;

    // --- เพิ่มระบบทางเลือก (Choices) ---
    bool hasChoice = false;
    string choiceA, choiceB; 
    string replyA, replyB;   

    NPC(string mName , string npcName, vector<string> npcMsgs, float startX, float startY, float scaleX = 1.f, float scaleY = 1.f) {
        mapNames = mName;
        name = npcName;
        messages = npcMsgs;
        sprite.setPosition(startX, startY);
        sprite.setScale(scaleX, scaleY); 
    }

    void setChoices(string cA, string cB, string rA, string rB) {
        hasChoice = true;
        choiceA = cA; choiceB = cB;
        replyA = rA; replyB = rB;
    }

    bool isPlayerNear(sf::FloatRect playerBounds) {
        sf::FloatRect interactArea = playerBounds;
        interactArea.left -= 30; interactArea.top -= 30;
        interactArea.width += 60; interactArea.height += 60;
        return interactArea.intersects(sprite.getGlobalBounds());
    }
};

class NPCManager {
public:
    vector<NPC> list; 
    map<string, sf::Texture> textureCache;

    void spawnNPC(string mapNames ,string name, vector<string> msgs, string imgPath, float x, float y, float scaleX = 1.f, float scaleY = 1.f) {
        if (textureCache.find(imgPath) == textureCache.end()) {
            sf::Texture tex;
            if (tex.loadFromFile(imgPath)) textureCache[imgPath] = tex;
        }
        NPC newNpc(mapNames,name, msgs, x, y, scaleX, scaleY);
        list.push_back(newNpc);
        list.back().sprite.setTexture(textureCache[imgPath]);
    }

    // --- ฟังก์ชันใหม่: ตั้งค่าทางเลือกให้ NPC ---
    void setLastNPCChoice(string cA, string cB, string rA, string rB) {
        if (!list.empty()) list.back().setChoices(cA, cB, rA, rB);
    }

    void drawAll(sf::RenderWindow& window, string currentMap) {
        for(auto& npc : list){
            if (npc.mapNames == currentMap) window.draw(npc.sprite);
        }
    }
};
#endif