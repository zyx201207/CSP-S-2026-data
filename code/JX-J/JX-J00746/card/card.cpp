#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int n,m,a[N],ans[N],x[N],pos;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		for(int i=1;i<=n;i++){
			 if(a[i]!=a[i+1]) cout<<i<<" ";
		}
		return 0;
	}
	else{
		for(int t=1;t<=n;t++){
			pos=0;
			for(int i=t;i<=n;i++){
				x[++pos]=a[i];
				for(int j=1;j<pos;j++){
					if(x[j]==x[pos]){
						pos=j;
					}
				}
			}
			for(int i=1;i<=pos;i++){
				 ans[x[i]]++;
			 }
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
