#include<iostream>
using namespace std;
int n,m,a[500005],nxt[500005],d[500005],ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(d[a[i]])nxt[i]=d[a[i]];
		d[a[i]]=i;
	}
	for(int st=1;st<=n;st++){
		bool flag[300005];
		for(int i=1;i<=300000;i++)flag[i]=0;
		for(int i=st;i<=n;i++){
			if(flag[a[i]]==0){
				ans[a[i]]++;
				flag[a[i]]=1;
			}
			if(nxt[i])i=nxt[i]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
}