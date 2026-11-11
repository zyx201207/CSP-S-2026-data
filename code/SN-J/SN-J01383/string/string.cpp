#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,asd=0;
	char s[10001][10001],f[10001][10001],c[3];
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		cin>>c[1];
		for(int j=1;j<=b;j++){
			s[i][j]=c[1];
		}
	}
	for(int i=a;i>=1;i--){
		for(int j=1;j<=b;j++){
			f[i][j]=s[i][j];
		}
	}
	for(int i=i;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(f[i][j]!=s[i][j]){
				asd++;
			}
		}				
	}
	cout<<asd;
	return 0;
}
