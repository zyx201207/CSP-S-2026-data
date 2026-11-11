#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001],c[300001],s[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=0;
		for(int j=1;j<=m;j++)b[j]=c[j]=0;
		for(int j=i;j<=n;j++){
			b[++l]=a[j];
			c[a[j]]++;
			if(c[a[j]]==2){c[a[j]]=1;l--;while(b[l]!=a[j]){c[b[l]]--;l--;}}
			
		}
		for(int j=1;j<=m;j++)if(c[a[j]]==1)s[a[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
