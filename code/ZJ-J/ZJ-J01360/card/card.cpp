#include<bits/stdc++.h>
using namespace std;
int n,maxn=1,m;
int a[501000],b[501000],f[501000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int tt=1;tt<=n;tt++){
		int k=0;
		for(int i=tt;i<=n;i++){
			bool f=1;
			for(int j=1;j<=k;j++){
				if(a[i]==b[j]){
					k=j-1;
					break;
				}
			}
			if(f==1){
				b[++k]=a[i];
			}
		}
		for(int i=1;i<=k;i++){
			f[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<' ';
	}
}