#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[300005],n,m;
void abab(int x){
	vector<bool> c(m+1,false);
	vector<long long> d(m+1,0);
	for(;x<=n;x++){
		if(c[a[x]]){
			for(long long i=d[a[x]];i<x;i++){
				c[a[i]]=false;
			}
		}
		c[a[x]]=true;
		d[a[x]]=x;
	}
	for(int l=1;l<=m;l++){
		if(c[l]){
			b[l]++; 
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		abab(i);
	}
	for(long long i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
