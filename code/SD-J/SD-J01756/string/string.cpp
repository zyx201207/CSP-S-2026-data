#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],t,w;
char b[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	t=1;
	w=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long num=0;
	while(t<w){
		int tge=a[t];
		char tou=b[t];
		int wge=a[w];
		char wei=b[w];
		t++;
		w--;
		if(tge<wge){
			int c=wge-tge;
			a[++w]=c;
		}
		else if(tge>wge){
			int c=tge-wge;
			a[--t]=c;
		}
		if(tou!=wei){
			num+=min(tge,wge);
		}
	}
	cout<<num;
	return 0;
}
