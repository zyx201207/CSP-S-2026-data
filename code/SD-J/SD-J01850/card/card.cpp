#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],r[M],s[M];
bool f[M]; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f[a[i]]==1){
			for(int j=r[a[i]];j<=i;j++){
				f[a[j]]=0;
			}
			r[a[i]]=i;
		} 
		r[a[i]]=i;
		f[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		if(f[i])s[i]++;
		f[i]=0;
	}
	for(int k=2;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(f[a[i]]==1){
				for(int j=r[a[i]];j<=i;j++){
					f[a[j]]=0;
				}
				r[a[i]]=i;
			} 
			f[a[i]]=1;
			r[a[i]]=i;
			
		}
		for(int i=1;i<=m;i++){
			if(f[i])s[i]++;
			f[i]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
}

