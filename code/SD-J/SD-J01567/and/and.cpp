#include<bits/stdc++.h >
using namespace std;
int n,m,a[2005],f[2005][2005]={0};
bool t[2005][2005]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[1][i]=a[i];
		t[i][i]=1;
	}
	if(m==1){
		int maxx=-1;
		for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
		cout<<maxx;
	}else if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}else if(m==n){
		long long maxx=1;
		for(int i=1;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
	}else if(m==n-1){
		long long maxx=1;
		for(int i=1;i<=n;i++){
			long long f=1;
			for(int j=1;j<=n,j!=i;j++){
				f=f&a[j];
			}
			maxx=max(maxx,f);
		}
		cout<<maxx;
	}else{
		for(int i=2;i<=m;i++){
			for(int j=1;j<=n;j++){
				long long h=0,g=0;
				for(int k=1;k<=n;k++){
					if(h<(f[i-1][j]&a[k])&&t[j][k]!=1){
						h=(f[i-1][j]&a[k]);
						g=k;
					}
				}
				t[j][g]=1;
				f[i][j]=h;
			}
		}
		int l=-1;
		for(int i=1;i<=n;i++){
			l=max(l,f[m][i]);
		}
		cout<<l;
	}
	return 0;
}
