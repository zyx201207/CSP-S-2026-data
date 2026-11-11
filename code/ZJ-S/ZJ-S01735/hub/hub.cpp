#include<bits/stdc++.h>
using namespace std;
int h[1000009],e[2000009],ne[2000009],idx=1;
void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
		}
		int l=0,r=n;
		while(l<r){
			int mid=l+r>>1;
		}
		cout<<n/2<<"\n";
	}
	return 0;
}
