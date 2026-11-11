#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const long long inf=1e13;
const int N=5e5+10;
unsigned long long a[N],p[N];
long long st[20][N];
long long n,m,ans;
void ST(){
	for(int i=1;i<=n;i++) st[0][i]=a[i];
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<(i-1))<=n;j++)
			st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}int query(int l,int r){
	int k=log2(r-l+1);
	return max(st[k][l],st[k][r-(1<<k)+1]);
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=p[i-1]+a[i];
	ST();
	int pos1=1,pos2=1;
	while(pos2<=n){
		int dif=p[pos2]-p[pos1-1];
//		cout<<pos1<<' '<<pos2<<' '<<dif<<' '<<(dif+m)/(pos2-pos1+1)<<' '<<query(pos1,pos2)<<endl;
		if((dif+m)/(pos2-pos1+1)>=query(pos1,pos2))
			ans=max(ans,pos2-pos1+1ll);
		else pos1++;
		pos2++;
	}cout<<ans;
	return 0;
}
/*
10 6
1 1 4 5 1 4 4 5 8 7
*/
