# 🎵 Stone Analysis

---

## 📌 Objectif

Créer un programme en **C++** capable de :
- Lire un fichier `.wav` (PCM 16bits, 48kHz, mono)
- Appliquer la **DFT** (Discrete Fourier Transform) sur le signal audio
- Extraire :
  - Les **N fréquences dominantes** du signal audio
  - OU **coder** un message secret dans les fréquences
  - OU **décoder** un message secret déjà caché
- Recomposer le signal modifié via **IDFT**

> ⛔ Aucune bibliothèque tierce n'est autorisée pour le traitement audio, les FFT/DFT ou la stéganographie !

---

## 🔧 Contraintes Techniques

- Format d’entrée : `.wav` **PCM**, 16 bits, 48 000 Hz, mono
- Complexité DFT/IDFT : `O(n²)` (implémentation naïve autorisée)
- Aucun changement **perceptible** du fichier audio en sortie
- Le fichier de sortie doit **conserver exactement le même header**
- Le message à encoder/décoder doit contenir :
  - Lettres **a-z**
  - Chiffres **0-9**
  - L’espace `" "`

---

## 🧩 Fonctionnalités

### 🔍 Analyse

- Extraction des **N fréquences dominantes**
- Affichage dans l’ordre **décroissant** de magnitude
- En cas d’égalité, ordre interchangeable

### 🕵️‍♀️ Encodage

- Coder un message texte dans des blocs audio via **modulation fréquentielle**
- Conserver le caractère **inaudible** du signal

### 🔓 Décodage

- Extraire un message secret en détectant les fréquences injectées
- Reconstruire la chaîne via une **table de correspondance**

---

## 🏗️ Architecture logicielle (C++)

### 🎯 Design Pattern retenu : Singleton + Template Method

**Pourquoi ?**
- Le Singleton centralise la configuration du traitement audio.
- Les différentes fonctionnalités (analyse, encodage, décodage) sont modulaires et interchangeables via des interfaces polymorphes.
- On anticipe l'ajout futur d'autres types de messages ou formats audio.
- Template Method permet d'overpass des implémentations précises

### 📁 Structure du projet

├── Makefile <br>
├── main.cpp <br>
├── include/ <br>
│ ├── AudioManager.hpp <br>
│ ├── WavFile.hpp <br>
│ ├── FourierTransform.hpp <br>
│ ├── Steganography.hpp <br>
│ └── Plugin.hpp <br>
├── src/ <br>
│ ├── AudioManager.cpp <br>
│ ├── WavFile.cpp <br>
│ ├── FourierTransform.cpp <br>
│ ├── Steganography.cpp <br>
│ └── Plugins/TDLRendererPlugin.cpp <br>
├── plugins/ <br>
├── assets/ <br>
│ └── stone_signal.wav <br>

---

## 🧩 Détails Techniques

### 🔊 Format WAV PCM 16bits Mono

- **Header** : 44 octets
- **Samples** : Entiers signés 16 bits (int16_t)
- 1 canal mono → chaque échantillon = 2 octets
- 48000 échantillons / seconde

### 🧮 Discrete Fourier Transform (DFT)

> Implémentation naïve en complexité `O(n²)`.

**Formule directe :**
X_k = Σ_{n=0}^{N-1} x_n * e^{-2πi * k * n / N}

**Formule inverse (IDFT) :**
x_n = (1/N) * Σ_{k=0}^{N-1} X_k * e^{2πi * k * n / N}


**Optimisation suggérée :**
- Pré-calcule des tables de sinus/cosinus
- Regroupement réel/imaginaire avec `std::complex<>`

---

## 🕵️‍♂️ Stéganographie Audio

### 🔐 Méthode proposée : *Frequency Mapping Encoding*

Chaque caractère est associé à une fréquence **inaudible ou subtile**, injectée dans le spectre.

**Étapes :**
1. Segmenter l'audio en **blocs** de taille fixe (ex. 1024 samples)
2. Pour chaque caractère :
   - Convertir en fréquence via table (`char -> freq`)
   - Injecter une sinusoïde à faible amplitude dans un bloc
3. Appliquer l’IDFT
4. Ré-assembler les blocs

**Décodage :**
- DFT sur chaque bloc
- Détection des pics correspondant aux fréquences mappées
- Reconstruction de la chaîne

> 🎧 Pour éviter la détection humaine : utiliser une **amplitude faible**, injection **temporaire et répartie**, et garder le **rapport signal/bruit**.

---

## 🧱 Exemple d’implémentation Singleton

```cpp
class AudioManager {
public:
    static AudioManager& getInstance() {
        static AudioManager instance;
        return instance;
    }

    void loadFile(const std::string& path);
    void analyzeTopFrequencies(int topN);
    void encodeMessage(const std::string& msg);
    void decodeMessage();

private:
    AudioManager() = default;
    std::vector<int16_t> samples;
    std::vector<int16_t> originalHeader;
};
```

## 📚 À faire

- Implémenter le parser WAV
- Coder la DFT / IDFT
- Définir une table char -> frequency
- Gérer les blocs d’encodage/décodage
- Ajouter l’option CLI
- Écrire la doc technique