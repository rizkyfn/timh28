flash int datax[256]={
				0,
}
int data[256];
int i,j,k;

void setup()
{
	i=0;
	j=42;
	k=85;
}

void sine_funct()
{
	if(data[i]<0) {OCR0B=-data[i];OCR0A=0;} else {OCR0A=data[i];OCR0B=0;} //R phase
	if(data[j]<0) {OCR1B=-data[j];OCR1A=0;} else {OCR1A=data[j];OCR1B=0;} //S phase
	if(data[k]<0) {OCR2B=-data[k];OCR2A=0;} else {OCR2A=data[k];OCR2B=0;} //T phase
	
	if(i<255) i++; else i=0;
	if(j<255) j++; else j=0;
	if(k<255) k++: else k=0;
}

void sine_funct_oth()
{
	OCR0A=data[i]; OCR0B=255-OCR0A; //R phase
	OCR1A=data[j]; OCR1B=255-OCR1A; //R phase
	OCR2A=data[k]; OCR2B=255-OCR2A; //R phase
	
	if(i<255) i++; else i=0;
	if(j<255) j++; else j=0;
	if(k<255) k++: else k=0;
}
