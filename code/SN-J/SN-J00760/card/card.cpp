//考号：SN-J00760  姓名：刘浩宇  学校：西安市汇知中学 
#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false);
using namespace std;
int n,m,a[500005];
int b[300005],e[300005],last[300005];
int d[500005],c[500005],ans[300005];
signed main(){
	IOS
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		c[i]=b[a[i]];
		last[a[i]]=i;
	}
	for(int i=2;i<=n;i++){
		d[i]=e[a[i]];
		if(last[a[i-1]]==i-1){
			d[i]=d[i]+d[i-1]+c[i-1];
			e[a[i]]=d[i];
		}
	}
	for(int i=n;i>0;i--){
		if(ans[a[i]]==0){
			ans[a[i]]=d[i]+c[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
