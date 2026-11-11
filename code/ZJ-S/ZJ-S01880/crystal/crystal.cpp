#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5000000],n,m;
int cha[5000005],qand[5000005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		cha[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		qand[i]+=qand[i-1]+cha[i];
	}
	int qian=0,hou=0,ge=1,ans=0;
	int jiage=0;
	while(qian<n){
		qian++;
		ge--;
		if(qian!=1)jiage-=qand[hou]-qand[qian-2];
		while(cha[hou+1]*(ge+1)+jiage<=m&&hou+1<n){
			hou++;
			ge++;
			jiage+=cha[hou]*ge;
		}
		ans=max(ans,ge+1);
	}
	
	cout<<max(1ll,ans);
}
/*

5 5
1 2 4 8 9
*/
