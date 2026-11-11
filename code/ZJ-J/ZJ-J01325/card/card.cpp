#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[300005],p[5005],k[5005],r;
int a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			f1=0;
		}
	}
	if(f1==1){
		for(int i=1;i<=n;i++){
			f[a[i]]=n-i+1;
		}
		for(int i=1;i<=m;i++){
			cout<<f[a[i]]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		memset(k,0,sizeof(k));
		r=i-1;
		for(int j=i;j<=n;j++){
			if(p[a[j]]==0||r<p[a[j]]){
				r++;
				k[r]=a[j];
				p[a[j]]=r;
			}
			else{
				r=p[a[j]];
			}
		}
		for(int j=i;j<=r;j++){
			f[k[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
}