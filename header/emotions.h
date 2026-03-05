#pragma once


enum class Emotion {
    Neutral,
    Happy,
    Angry,
    Sad
};


inline float getEmotionMultiplier(Emotion attacker, Emotion defender) {
    // wins (x1.5 dmg)
    if (attacker == Emotion::Happy && defender == Emotion::Angry) return 1.5f;
    if (attacker == Emotion::Angry && defender == Emotion::Sad) return 1.5f;
    if (attacker == Emotion::Sad && defender == Emotion::Happy) return 1.5f;
    
    // loses (x0.8 dmg)
    if (attacker == Emotion::Happy && defender == Emotion::Sad) return 0.8f;
    if (attacker == Emotion::Angry && defender == Emotion::Happy) return 0.8f;
    if (attacker == Emotion::Sad && defender == Emotion::Angry) return 0.8f;

    // neutral
    return 1.0f;
}