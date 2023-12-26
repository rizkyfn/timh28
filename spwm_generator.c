flash int datax[256]={
128,
131,
134,
137,
140,
143,
147,
150,
153,
156,
159,
162,
165,
168,
171,
174,
177,
180,
182,
185,
188,
191,
194,
196,
199,
201,
204,
206,
209,
211,
214,
216,
218,
220,
223,
225,
227,
229,
230,
232,
234,
236,
237,
239,
240,
242,
243,
245,
246,
247,
248,
249,
250,
251,
252,
252,
253,
253,
254,
254,
255,
255,
255,
255,
255,
255,
255,
255,
255,
254,
254,
253,
253,
252,
251,
250,
249,
249,
247,
246,
245,
244,
243,
241,
240,
238,
237,
235,
233,
231,
229,
228,
226,
224,
221,
219,
217,
215,
212,
210,
208,
205,
203,
200,
198,
195,
192,
189,
187,
184,
181,
178,
175,
172,
169,
166,
163,
160,
157,
154,
151,
148,
145,
142,
139,
136,
132,
129,
126,
123,
120,
117,
114,
111,
107,
104,
101,
98,
95,
92,
89,
86,
83,
80,
77,
74,
72,
69,
66,
63,
61,
58,
55,
53,
50,
48,
45,
43,
41,
38,
36,
34,
32,
30,
28,
26,
24,
22,
21,
19,
17,
16,
14,
13,
12,
10,
9,
8,
7,
6,
5,
4,
4,
3,
2,
2,
1,
1,
1,
0,
0,
0,
0,
0,
1,
1,
1,
2,
2,
3,
3,
4,
5,
6,
6,
7,
9,
10,
11,
12,
14,
15,
17,
18,
20,
21,
23,
25,
27,
29,
31,
33,
35,
37,
40,
42,
44,
47,
49,
52,
54,
57,
59,
62,
65,
67,
70,
73,
76,
79,
82,
85,
88,
91,
94,
97,
100,
103,
106,
109,
112,
115,
118,
121,
125,
}
int data[255];
int i,j,k,l,m,n,o;

void setup()
{
	i=0;
	j=85;
	k=170;
	m=128;
	n=213;
	o=43;
	for(l=0;l<255;l++) data[l]=datax[l];
}

void attenuator(float atten)
{
	for(l=0;l<255;l++) data[l]=atten*datax[l]; //atten from 0.05 to 1.0
}

void sine_funct()
{
	if(data[i]<0) {OCR0B=-data[i];OCR0A=0;} else {OCR0A=data[i];OCR0B=0;} //R phase
	if(data[j]<0) {OCR1B=-data[j];OCR1A=0;} else {OCR1A=data[j];OCR1B=0;} //S phase
	if(data[k]<0) {OCR2B=-data[k];OCR2A=0;} else {OCR2A=data[k];OCR2B=0;} //T phase
	
	if(i<254) i++; else i=0;
	if(j<254) j++; else j=0;
	if(k<254) k++: else k=0;
}

void sine_funct_oth()
{
	OCR0A=data[i]; OCR0B=255-OCR0A; //R phase
	OCR1A=data[j]; OCR1B=255-OCR1A; //S phase
	OCR2A=data[k]; OCR2B=255-OCR2A; //T phase
	
	if(i<254) i++; else i=0;
	if(j<254) j++; else j=0;
	if(k<254) k++: else k=0;
}

void sine_funct_oth_2()
{
	OCR0A=data[i]; OCR0B=data[m]; //R phase
	OCR1A=data[j]; OCR1B=data[n]; //S phase
	OCR2A=data[k]; OCR2B=data[o]; //T phase
	
	if(i<254) i++; else i=0;
	if(j<254) j++; else j=0;
	if(k<254) k++: else k=0;
	if(m<254) m++; else m=0;
	if(n<254) n++; else n=0;
	if(o<254) o++: else o=0;
}
void main()
{
	setup();
	while(1)
	{
		sine_funct_oth();
		delay_us(75); //change frequencies from 75us to 7.5ms (50Hz to 0.5Hz)
	}
}
