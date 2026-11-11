#include<bits/stdc++.h>
using namespace std;
int g[10005],h[10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a1[100005];
	bool k;
	int l=0;
	int a=0;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
		a=a1[i]-a1[i-1];
		if(a==l){
			k=true;
		}
		l=a1[i]-a1[i-1];
	}
	int y=0;
	if(k==true){
		for(int i=1;i<=n;i++){
			g[i]=g[i-1]+a1[i];
		}
		int ll=g[n];
		for(int i=1;i<=n;i++){
			if(ll-g[i]>=m){
				y=ll-g[i];
			}
		}
		cout<<y;
	}else{
		cout<<1;
	}
	
}
