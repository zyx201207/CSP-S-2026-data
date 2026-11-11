#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
    string a,b[100000];
	int c,d,e,f=0,g=1,h=0,k=0,l=0;
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>d>>a;
		for(int j=1;j<=d;j++){
			b[f]=a;
			f++;
			
		}
	} 
	
	
	while(g!=0){
		if(b[h]!=b[f-h-1]){
	
			b[f-h]=b[h];
			h++;
		}else{
			k++;
		}
		if(h+k>=f){
			cout<<h;
			g=0;
		}
	}
	
	return 0;
} 

