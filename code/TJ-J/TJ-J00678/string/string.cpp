#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,c[10007];
	string b[10007],d;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>c[i]>>b[i];
	}
	for(int i=0;i<a;i++){
		if(i!=a-1){
			if(b[i]==b[i+1]){
				cout<<0;
			}
			else cout<<1;
		}
	}
	return 0;
} 
