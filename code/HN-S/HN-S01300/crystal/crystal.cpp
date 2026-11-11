#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
long long a[500010],cha[500010],he[500010],sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		cha[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)
		he[i]=he[i-1]+cha[i];
	for(int i=2;i<=n;i++)
		sum[i]=sum[i-1]+(i-1)*cha[i];
	int tmp=upper_bound(sum+1,sum+n+1,m)-sum-1;
	for(int i=tmp+2;i<=n;i++){
		cnt++;
		int k=sum[i-tmp]+(he[i]-he[i-tmp])*(i-tmp-1);
		if(sum[i]-k<m){
			cout<<i-cnt;
			return 0;
		}
	}
	cout<<tmp;
}
