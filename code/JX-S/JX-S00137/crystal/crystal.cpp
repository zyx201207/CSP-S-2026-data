#include<bits/stdc++.h>
using namespace std;
long long n,m,lmj[1000001],sum[1000001],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>lmj[i];
	}
	sort(lmj+1,lmj+1+n);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(lmj[i]-lmj[i-1])*(i-1);
		long long cnt=sum[i],z=1;
		if(sum[i]<=m){
			ans=i;
		}
		else{
			while(cnt-(lmj[i]-lmj[z])>m&&i-z>ans){
				cnt-=lmj[i]-lmj[z];
				z++;
			}
			if(i-z>ans){
				ans=i-z;
			}
		}
	}
	cout<<ans;
	return 0;
}
