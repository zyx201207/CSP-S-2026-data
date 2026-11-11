#include<bits/stdc++.h>
using namespace std;
long long b[10000000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	
	int a,t=0;
	char n[200010];
	string c;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
		cin>>n[i];
		for(int j=1;j<=b[i];j++){
			t++;
			c[t]=n[i]; 

		}
	}
	
		string d; 
		string e;
		int jj=1,s=0,ss=0;
		for(int i=t/2;i>=1;i--){
			d[jj]=c[i];
			jj+=1;
			ss++;
		}

			
			
			jj=1;
			for(int i=t-ss+1;i<=t;i++){
				if(c[i]!=d[jj]){
					s++;
					
				}
			}	
			
		
	
	cout<<s;
	return 0;
	
} 
