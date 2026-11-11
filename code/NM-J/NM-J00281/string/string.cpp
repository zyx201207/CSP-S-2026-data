#include<bits/stdc++.h>
using namespace std;
long long a,b=0,c[1000005]={},e=0,e1=0,e2=0;
char d[1000005]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	b=a/2+a%2;
	for(int i=1;i<=a;i++){
		cin>>c[i]>>d[i];
		e1+=c[i];
	}
	for(int i=1;i<=b;i++){
		if(d[i]==d[a-i+1]){
			e2=c[i]-c[a-i+1];
		}
		else{
		e2=e2+c[i]-c[a-i+1];
		e+=min(c[i],c[a-i+1]);
		}
		if(e2>0){
		if(d[i]==d[a-i]){
			e2=e2-c[a-i];
		}
		else{
		e2=e2-c[a-i];
		e+=min(e2,c[a-i]);
		}
		}
		else{
		if(d[i+1]==d[a-i+1]){
			e2+=c[i+1];
		}
		else{
		e2+=c[i];
		e+=max(e2,c[i+1]);
		}
		}
	}
	cout<<e;
	return 0;
}
