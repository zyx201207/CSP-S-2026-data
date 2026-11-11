#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const long long inf=1e13;
long long n,m,ans;
unsigned long long a[6000],p[6000];
long long st[20][6000];
void ST(){
	for(int i=1;i<=n;i++) st[0][i]=a[i];
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<(i-1))<=n;j++)
			st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}int query(int l,int r){
	int k=log2(r-l+1);
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal3.in","r",stdin);
//	freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ST();
	for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
	cout<<p[n]<<endl;
	for(int i=1;i<=n;i++){
		int j=i+3800;
		int sum=0;
		for(int k=i;k<=j;k++)
			sum+=99943-a[k];
		if(sum<=m){
			cout<<p[j]-p[i-1]<<' '<<sum<<endl;
			cout<<i<<' '<<j<<' '<<((sum+m)/(j-i+1)>=query(i,j))<<endl;
			return 0;
		}
//			return 0;
		}
	return 0;
}
