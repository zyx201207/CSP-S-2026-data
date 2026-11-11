#include<bits/stdc++.h>
using namespace std;
string e,s,v[10000]={};
long long a,b,c[10000]={},d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a-1;i++){
		cin>>c[i]>>v[i];
    }
	for(int i=0;i<=a-1;i++){
		for(int j=0;j<=a-1;j++){
			if(v[i]!=v[j]){
				b=b+c[j];
			}
		}
		d=max(b,d);
		b=0;
	}
	cout<<d;
	return 0;
} 
