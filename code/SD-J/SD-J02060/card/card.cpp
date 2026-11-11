#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],q[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++)
			if(!b[a[j]])q[++cnt]=a[j],b[a[j]]=cnt;
			else{
				for(int k=b[a[j]]+1;k<=cnt;k++)b[a[k]]=0,q[k]=0;
				cnt=b[a[j]];
			}
		for(int j=1;j<=cnt;j++)ans[q[j]]++,q[j]=0;
		for(int j=1;j<=m;j++)b[j]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
