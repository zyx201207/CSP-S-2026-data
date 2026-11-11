#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,cnt,a[500005],ans[500005],f[500005],q[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[j]=0,q[j]=0;
		cnt=0;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(q[cnt]!=a[j]){
					f[q[cnt]]=0;
					cnt--;
				}
			}
			else{
				q[++cnt]=a[j];
				f[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
/*
CCF have no egg！！！
十年OI一场空，不开long long见祖宗
不会做怎么办……
我的洛谷账号：wudongcheng0223
*/