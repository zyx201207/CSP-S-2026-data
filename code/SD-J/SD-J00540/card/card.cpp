#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300005],n,m,w,b[500005],c[300005];
bool t=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]<b[i-1]) t=0;
		a[b[i]]=i;
	}
	for(int i=1;i<=n;i++){
		bool d[300005];
		for(int j=i;j<=n;j++){
			if(d[a[j]]==1){
				for(int k=j-1;k>=i;k++){
					if(a[k]==a[j]) break;
					d[a[k]]=0;
				}
			}
			else d[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(d[j]) c[j]++;
		}
	}
	if(t) for(int i=1;i<=m;i++) cout<<a[i]<<" ";
	else for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
