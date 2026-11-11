#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N],a[1001],t[1001],b[1001][1001],k[1001],tr[1001],c,n,m,d,q,l,r;
int sou(int x){
	int ans=1e9;
	if(x==r)return 0;
	for(int i=1;i<=m;i++){
		if(b[x][i]!=0 && tr[i]==0){
			tr[x]=1;
			ans=min(ans,b[x][i]+sou(i));
			tr[x]=0;
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k[i];j++){
			for(int p=1;p<=k[i];p++){
				if(j!=p){
				b[a[p]][a[j]]=t[p]+t[j];
				b[a[j]][a[p]]=t[p]+t[j];}
			}
		}
	}
	while(q--){
		cin>>l>>r;
		cout<<sou(l)+w[l]+w[r]<<endl;
	}
	return 0;
}
