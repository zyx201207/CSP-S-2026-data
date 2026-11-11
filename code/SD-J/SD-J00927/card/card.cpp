#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int flag=0;
int id[N];
int vis[N];
int a[N],h[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	    h[a[i]]=i;
		if(a[i]<a[i-1]) flag=1;
	}
	if(flag==0){
		for(int i=1;i<=m;i++){
			if(h[i]!=0) cout<<h[i]<<" ";
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			cout<<1;
		}
	}
	return 0;
}
