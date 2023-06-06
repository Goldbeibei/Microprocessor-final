#include <IRremote.h>

IRsend irsend;


void setup()
{

}
// on 
// Raw: (59) 8000, -4000, 520, -1564, 524, -524, 520, -540, 500, -536, 500, -1592, 500, -528, 520, -532, 520, -548, 500, -532, 520, -548, 500, -532, 520, -548, 500, -532, 520, -552, 496, -540, 500, -524, 520, -1584, 500, -1564, 520, -540, 500, -536, 500, -548, 500, -532, 520, -1600, 500, -540, 500, -1576, 500, -1588, 520, -1576, 500, -540, 500, 
 
 
// off
// Raw: (59) 8000, -4000, 524, -1544, 552, -496, 548, -512, 524, -500, 548, -1556, 528, -520, 524, -500, 548, -520, 528, -1532, 552, -1548, 524, -516, 524, -496, 552, -520, 524, -512, 528, -512, 524, -508, 548, -496, 552, -504, 548, -504, 552, -516, 504, -528, 552, -1572, 500, -536, 504, -1572, 500, -540, 500, -540, 496, -548, 520, -1540, 552, 

// right on
unsigned int sendbuf1[] = { 
9032,4468,892,1356,580,1700,548,556,552,560,544,568,544,564,548,1704,540,1672,580,1700,548,1668,588,1680,552,1680,572,556,556,560,552,560,536,1700,548,568,552,560,564,548,544,568,544,568,544,552,568,544,544,568,544,576,536,560,552,560,552,560,552,560,552,560,564,544,548,564,548,564,544,568,544,568,544,552,560,560,540,1688,576,548,552,1676,572,556,564,548,544,568,544,564,548,564,544,560,552,560,552,560,552,560,572,540,552,560,536,576,544,556,564,1660,572,568,544,568,544,560,552,560,552,560,548,564,536,576,536,572,544,556,564,548,544,568,544,568,544,564,548,572,540,560,548,560,552,560,552,560,552,560,540,572,544,568,544,552,568,544,564,1664,584,548,552,560,552,560,552,560,548,564,536,572,540,560,564,548,564,548,544,568,544,568,544,1676,576,1664,580,560,552,560,552,560,544,568,544,564,548,564,544,568,544,568,544,1676,568,1676,576,1664,572,568,544,568,544,20164};

// right off
unsigned int sendbuf2[] = { 
9032,4476,884,1384,544,1708,548,556,544,568,544,568,544,564,544,1708,540,1708,548,1672,576,1700,540,1704,540,1676,588,548,552,560,548,564,548,1676,568,572,544,556,544,568,544,568,544,564,548,564,544,568,544,560,552,560,552,560,552,560,552,560,552,560,544,568,544,564,544,568,544,568,544,556,544,572,540,572,540,572,540,1676,576,560,552,1676,572,556,544,568,544,568,544,564,548,560,548,564,548,560,552,560,552,560,552,560,544,568,544,564,548,564,544,1672,584,548,552,560,552,560,552,560,548,564,548,560,540,572,548,564,544,568,544,568,544,556,564,548,544,572,536,576,536,576,536,560,552,560,552,560,552,560,544,568,544,568,544,564,548,564,544,568,544,560,552,560,552,560,552,560,540,572,536,576,536,576,544,552,548,564,544,568,544,1684,572,560,552,1672,580,560,540,560,552,560,544,568,544,568,544,1680,572,1676,580,1664,580,560,536,1676,576,564,544,568,544,568,544,20172,516,1712,540,624,520,616,508,1712,544,608,524,612,524,1748,536,620,516,620,540,584,540,596,516,620,508,616,544,592,544,676,548,1676,544,620,512,620,516,620,516,612,520,612,524,612,520,704,508,620,516,596,540,608,528,608,540,596,520,616,508,616,520,700,544,600,512,608,528,608,516,620,516,620,516,608,520,616,520,700,520,616,520,612,512,624,512,1712,536,616,528,1700,552,612,520,700,520,612,512,624,512,624,512,612,524,612,512,624,520,592,532,712,532,1688,548,616,516,608,528,1700,552,612,520,1704,540,612,520,708,620,20164};

// middle on
unsigned int sendbuf3[] = { 
9068,4484,884,1396,532,1708,548,592,532,592,548,588,548,588,544,592,532,1764,532,596,548,1700,540,1716,540,588,544,592,544,584,552,584,540,656,540,584,552,584,548,588,544,592,548,576,544,592,544,588,548,648,536,600,536,1712,544,584,544,592,544,1708,540,592,540,596,540,1760,548,592,544,580,564,572,564,572,544,592,544,584,552,584,540,660,548,588,536,584,564,572,544,592,544,592,544,580,556,588,536,636,572,592,544,580,556,580,544,584,552,584,552,588,536,596,540,672,544,592,544,580,544,592,544,584,552,584,540,596,540,584,552,668,548,576,544,592,544,592,544,592,544,588,536,588,548,588,548,660,548,588,544,592,544,580,564,568,548,588,548,584,552,584,548,660,552,584,544,592,544,580,544,592,544,592,544,584,552,584,540,672,548,588,536,584,568,568,544,592,548,588,544,580,556,588,536,672,540,584,552,584,552,584,544,592,544,580,544,592,544,592,544,668,552,584,540,1712,548,580,544,592,544,1684,572,580,556,584,540,1748,572,592,544,588,548,588,536,584,552,588,548,584,540,596,548,676,544,1680,572,588,536,600,536,588,548,588,548,588,544,592,544,664,564,572,544,592,544,584,552,584,540,596,540,584,552,584,544,676,544,592,544,592,544,588,536,600,536,588,548,588,548,584,540,684,544,592,544,580,544,592,544,1688,564,1688,592,1652,572,592,544,676,544,592,544,584,552,584,572,564,540,584,552,584,548,588,544,680,544,1680,584,576,548,584,540,1688,568,1712,540,1688,572,580,544,672,652,20168};
// middle off
unsigned int sendbuf4[] = { 
9068,4500,888,1388,548,1708,540,588,544,592,544,592,532,596,540,584,552,1748,548,580,544,1708,552,1700,556,580,552,584,536,600,536,588,548,648,544,592,544,580,544,592,544,592,544,584,552,584,540,596,540,644,552,584,544,1708,552,588,544,580,544,1712,548,580,548,588,548,1764,540,588,564,568,544,592,544,588,548,588,548,576,548,588,548,648,544,592,544,580,564,568,548,588,548,584,552,584,548,588,536,636,560,592,544,588,548,588,536,596,540,588,548,584,548,588,544,668,544,592,532,596,540,596,540,584,552,584,540,596,536,600,532,676,544,580,544,592,544,584,552,584,540,596,540,596,540,584,564,644,548,588,548,588,544,592,544,588,536,600,536,588,548,584,552,672,532,592,544,592,544,592,532,592,544,596,540,584,552,584,540,668,544,592,544,592,544,580,544,592,544,588,548,588,536,596,540,672,536,600,544,580,544,592,544,588,548,592,532,596,540,596,540,668,540,596,540,1688,572,580,544,592,544,1676,580,584,536,600,536,1752,572,584,552,584,540,596,540,596,540,584,548,588,544,592,532,688,548,1676,576,588,536,588,548,584,540,600,544,588,532,592,544,680,544,584,552,584,552,584,540,596,540,584,544,592,544,592,544,676,544,588,536,600,536,596,540,584,552,584,540,596,548,588,532,692,532,592,544,596,540,584,552,1676,564,600,536,1688,572,580,544,676,548,596,540,584,548,588,548,588,536,600,544,580,544,588,548,676,544,1688,580,572,548,588,536,1688,572,592,532,1696,572,580,544,668,652,20156};
// left on
unsigned int sendbuf5[] = { 9068,4504,892,1388,540,1708,548,580,548,588,540,596,536,600,536,588,544,1752,544,588,544,1688,576,1676,580,572,552,584,544,592,544,580,544,652,544,592,544,588,536,600,536,588,548,588,548,588,544,588,548,640,544,588,548,1676,576,584,552,584,572,1656,572,580,544,592,544,1744,572,588,536,600,536,584,572,564,540,596,548,588,532,592,544,652,548,588,548,584,548,588,548,588,536,600,536,588,544,588,580,592,600,560,540,584,552,584,544,592,548,588,544,580,544,592,544,672,540,596,540,584,548,588,544,592,544,592,532,592,544,592,544,668,540,584,552,584,552,584,540,596,532,592,544,592,544,592,544,660,552,584,536,600,536,600,536,588,548,588,544,592,544,588,536,676,532,596,540,596,540,584,552,584,540,596,544,592,532,592,544,676,536,588,544,600,536,588,548,584,540,600,536,584,548,588,544,668,544,592,544,584,552,584,540,596,540,584,552,584,536,600,544,676,508,616,520,1712,568,584,524,612,540,1688,576,584,536,588,544,1732,568,596,544,592,532,592,544,592,544,592,544,588,536,596,540,684,536,1688,572,592,508,616,520,616,544,592,520,612,536,596,540,684,536,588,524,612,520,612,524,612,536,588,548,588,544,588,548,672,552,584,516,620,544,592,508,616,544,592,544,592,544,584,540,684,536,600,512,624,536,584,548,1680,572,1684,540,1708,544,620,512,720,516,608,544,592,544,592,520,616,532,592,544,584,552,584,540,680,540,1688,572,592,520,616,532,1696,572,1676,544,1708,536,616,532,692,624,20156};

// left off
unsigned int sendbuf6[] = {
9068,4496,892,1388,548,1680,576,588,544,580,544,592,544,588,548,588,536,1736,592,560,548,1680,572,1684,572,584,572,564,540,584,548,588,548,648,544,592,532,592,544,592,544,592,544,584,540,596,540,584,552,644,540,596,548,1680,572,580,544,592,544,1712,536,592,540,596,540,1748,572,580,544,592,544,592,532,596,540,596,540,584,540,596,540,656,536,588,544,592,544,592,544,592,532,600,536,600,536,584,552,636,572,580,544,600,536,600,536,584,540,600,536,596,536,600,532,680,532,592,520,620,540,584,552,584,516,620,540,596,540,584,544,676,532,592,544,592,544,584,540,596,540,600,536,596,540,584,528,684,544,588,548,588,520,616,532,600,512,624,536,588,536,600,512,696,544,592,520,616,508,616,544,596,540,584,552,584,540,596,540,668,536,600,532,592,520,616,544,592,520,612,512,624,536,600,536,672,512,612,520,616,520,616,520,616,520,604,544,596,516,608,524,684,528,608,516,1712,540,624,520,616,508,1712,544,608,524,612,524,1748,536,620,516,620,540,584,540,596,516,620,508,616,544,592,544,676,548,1676,544,620,512,620,516,620,516,612,520,612,524,612,520,704,508,620,516,596,540,608,528,608,540,596,520,616,508,616,520,700,544,600,512,608,528,608,516,620,516,620,516,608,520,616,520,700,520,616,520,612,512,624,512,1712,536,616,528,1700,552,612,520,700,520,612,512,624,512,624,512,612,524,612,512,624,520,592,532,712,532,1688,548,616,516,608,528,1700,552,612,520,1704,540,612,520,708,620,20164};


void loop() {
  testRaw("RAW1", sendbuf1, sizeof(sendbuf1)/sizeof(int));
  delay(1000);
  testRaw("RAW2", sendbuf2, sizeof(sendbuf2)/sizeof(int));
  delay(1000);
  testRaw("RAW3", sendbuf3, sizeof(sendbuf3)/sizeof(int));
  delay(1000);
  testRaw("RAW4", sendbuf4, sizeof(sendbuf4)/sizeof(int));
  delay(1000);
  testRaw("RAW5", sendbuf5, sizeof(sendbuf5)/sizeof(int));
  delay(1000);
  testRaw("RAW6", sendbuf6, sizeof(sendbuf6)/sizeof(int));
  delay(1000);
}

void testRaw(char *label, unsigned int *rawbuf, int rawlen) {
    irsend.sendRaw(rawbuf, rawlen, 38 /* kHz */);
    delay(200);
}   
