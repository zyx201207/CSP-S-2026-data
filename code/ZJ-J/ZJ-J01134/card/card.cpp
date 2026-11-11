#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		b[i]=c[a[i]];
		if(c[a[i]]==0)c[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			d[a[j]]++;
			while(b[j]!=0)j=b[j];
		}
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	return 0;
}
