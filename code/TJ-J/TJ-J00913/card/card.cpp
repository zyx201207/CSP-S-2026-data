#include <bits/stdc++.h>
using namespace std;
int n,m;
int f[300005];
int f1[300005];
int b[300005];
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]++;
	}
	if(n<=500){
		for(int o=1;o<=n;o++){
			memset(b,0,sizeof(b));
			int l=0;
			for(int i=o;i<=n;i++){
				for(int j=1;j<=l;j++){
					if(a[i]==b[j]){
						for(int k=j;k<=l;k++)b[i]=0;
						l=j-1;
					}
				}
				b[++l]=a[i];
			}
			for(int i=1;i<=l;i++)f1[b[i]]++;
		}
		for(int i=1;i<=m;i++)cout<<f1[i]<<" ";
		return 0;
	}
	f[a[n]]=n;
	for(int i=1;i<=m;i++)cout<<f[i]<<" ";
	return 0;
}
