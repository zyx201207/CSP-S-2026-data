#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
int n,m,a[maxn],c[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		bitset<maxm>f;
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				bool o=0;
				for(int k=i;k<j;k++){
					if(a[k]==a[j]) o=1;
					if(o) f[k]=0;
				}
			}
			f[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(f[j]) c[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}
/*
By ZJ-J00357.
Luogu UID:1086453.
*/