# randomWriter

This program is written in c++. My original code is contained in the 'src' folder within the RandomWriter.cpp file.
All the support files necessary for a clean execution have been included. To execute RamdomWriter.cpp: 

1. Download Qt Creator (a free platform) or use any other platform you prefer.
2. Right click on 'RandomWriter.pro' file and direct the cursor to Qt Creator or your preferred platform.
3. Find RandomWriter.cpp (located within the 'src' folder) and execute the code.

The program currently reads one of three source texts (included), builds an order-k Markov model from that text, and generates random output that follows the frequency patterns of the model.

The source text is read in as a string and the user is prompted for an "order of analysis" between 0 and 10. An order-k 
model generates each character as a function of the k-character sequence preceding it.

A 0-order model therefore uses the frequency with which each character occurs in the source text and uses that as a weight 
for choosing the next letter. Each character in the randomly generated text occurs with a fixed probablility independent 
of previous characters. However for any k>0 model each character is chosen conditional on the k-characters that preceed 
it in the source text. 

The implementation that anaylzes the text takes in a string variable containing the text and an integer k. It returns a Map 
where each key is a k-character sequence found in the string. The associated value is a vector of all the characters that 
follow that seed in the string. This vector will likely contain multiple entries and duplicate values. These duplicates 
represent higher probability transitions from the Markov state.
