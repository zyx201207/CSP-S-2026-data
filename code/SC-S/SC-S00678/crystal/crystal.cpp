#include<bits/stdc++.h>
using namespace std;
long long shuijing[500005],cha[500005];
long long n,m;
long long gett(long long x){
	long long num=0,used=0;
	for(int i=1;i<=n;i++){
		long long c=x-shuijing[i];
		if(c<0){
			num=i-1;
			break;
		}
		cha[i]=c;
	}
	for(int i=num;i>=1;i--){
		used+=cha[i];
		if(used>m){
			return num-i;
		}
	}
	return num;
}

bool pd(long long x){
	long long num=0,used=0;
	for(int i=1;i<=n;i++){
		long long c=x-shuijing[i];
		if(c<0){
			num=i-1;
			break;
		}
		cha[i]=c;
	}
	for(int i=num;i>=1;i--){
		used+=cha[i];
		if(used>m){
			return 1;
		}
	}
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//--------------------加速
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>shuijing[i];
	}
	sort(shuijing+1,shuijing+n+1);
	if(n==1){
		cout<<1;
		return 0;
	}
	if(m==0){
		long long shu2=shuijing[1],ans=0,aaa=0;
		for(int i=1;i<=n;i++){
			if(shuijing[i]==shu2){
				aaa++;
			}
			else{
				shu2=shuijing[i];
				aaa=1;
			}
			if(ans<aaa){
				ans=aaa;
			}
		}
		cout<<ans;
		return 0;
	}
	long long ccc=shuijing[2]-shuijing[1];
	bool flag=1;
	for(int i=1;i<n;i++){
		if(shuijing[i]+ccc!=shuijing[i+1]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		double aww=sqrt(2*m/ccc+0.25)+0.5;
		cout<<int(aww);
	}
	else{
		long long l=1,r=n,ans=0;
		while(l<=r){
			long long mid=(l+r)>>1;
			long long b=gett(shuijing[mid]);
			if(b>ans){
				ans=b;
			}
			if(pd(shuijing[mid])){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
			cout<<ans;
	}
		
	return 0;
}
