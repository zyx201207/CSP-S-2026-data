#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		long long l=i-1,sum=0,cnt=1;
		while(l>=1&&sum<=m){
			long long y=a[i]-a[l];
			if(y>(m-sum)) break;
			sum+=y;
			cnt++;
			l--;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}//zmwjzs                                              
