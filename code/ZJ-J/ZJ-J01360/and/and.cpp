#include<bits/stdc++.h>
using namespace std;
int n,maxn=1,m,sum;
int kk;
int a[201000],z[201000],f[200010][31],s,b[200100];
void rjz1(int x,int i){
	int k=0;
	while(x!=0){
		f[i][++k]=x%2;
		x=x/2;
	}
}
bool ss(int x){
	for(int i=1;i<=kk;i++){
		if(f[b[i]][x]==0) return 0;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	z[1]=1;
	for(int i=2;i<=30;i++){
		z[i]=z[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		rjz1(a[i],i);
	}
	for(int i=30;i>=1;i--){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(f[j][i]==1) ans++;
		}
		if(ans>=m){
			for(int j=1;j<=n;j++){
				if(f[j][i]==1) b[++kk]=j;
			}
			for(int j=1;j<=i;j++){
				int anss=0;
				for(int j=1;j<=kk;j++){
					if(b[j]==0) continue;
					if(f[b[j]][i]==1) anss++;
				}
				if(anss>=m&&anss<ans){
					for(int j=1;j<=n;j++){
						if(f[b[j]][i]==0) {
							b[j]=0;
							ans--;
						}
					}
				}
			}
			for(int j=1;j<=i;j++){
				if(ss(j)) sum+=z[j];
			}
			break;
		}
	}
	cout<<sum;
}