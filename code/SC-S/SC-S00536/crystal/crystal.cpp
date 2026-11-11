#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],ans=1,i,tpa,tpb;
bool cheak(long long x){
	int sum=0;
	for(int j=i;j>=i-x+1;j--){
		sum+=a[i]-a[j];
	}
	return sum<=m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)tpa=1;
		if(i!=1&&i!=2&&((a[i]-a[i-1])!=(a[i-1]-a[i-2])))tpb=1;
	}
	if(!tpa){
		long long now=1;
		while(m>=now){
			ans++;
			m-=now;
			now++;
		}
		cout<<min(ans,n);
		return 0;
	}if(!tpb){
		long long cha=a[2]-a[1],now=1;
		while(m>=now*cha){
			ans++;
			m-=now*cha;
			now++;
		}
		cout<<min(ans,n);
		return 0;
		
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(cheak(mid)){
				ans=max(ans,mid);
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
	}
	cout<<ans;
	return 0;
}