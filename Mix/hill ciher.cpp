#include<iostream>
#include<cmath>
 
using namespace std;
 
float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
void getmesage()
{
	char msg[3];
	cout<<"Enter the Key\n";
	for(int i= 0; i < 3 ; i++)
	{
		for(int j = 0; j < 3;j++)
		{
			cin>>a[i][j];
			c[i][j]=a[i][j];
		}
	}
	cout<<"Enter the message\n";
	for(int j =0 ;j<3 ;j++)
	{	
		cin>>msg[j];
		mes[j][0] = msg[j] - 97;
		
	}
}
void encryption()
{
	for(int i=0;i<3 ;i++)
		for(int j = 0; j < 1; j++)
            for(int k = 0; k < 3; k++)	
					encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];

	cout<<" The Encrpyted message is\n ";
	for(int l=0;l<3;l++)
		cout<<(char)(fmod(encrypt[l][0], 26) + 97)<<" ";
}
void inverse()
{
int i, j, k;
    float p, q;
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            if(i == j)
                b[i][j]=1;
            else
                b[i][j]=0;
        }
        
    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = c[i][k];
            q = c[k][k];
                
            for(j = 0; j < 3; j++) {
                if(i != k) {
                    c[i][j] = c[i][j]*q - p*c[k][j];
                    b[i][j] = b[i][j]*q - p*b[k][j];
                }
            }
        }
    }
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            b[i][j] = b[i][j] / c[i][i];
    
}
void decryption() {
    int i, j, k;
    
    inverse();
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
                decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
    
    cout<<"\nDecrypted string is: ";
    for(i = 0; i < 3; i++)
        cout<<(char)(fmod(decrypt[i][0], 26) + 97)<<" ";
    
    cout<<"\n";
}
int main()
{
	getmesage();
	encryption();
	decryption();
	return 0;
}
