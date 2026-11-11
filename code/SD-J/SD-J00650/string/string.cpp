#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char ip;
}a[200010];
long long sum[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].ip;
		sum[i]=sum[i-1]+a[i].x;
	}
	long long zh=(sum[n]+1)/2;
	int l=1,r=n,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(sum[mid]>=zh){
			res=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
//	cout<<res<<" ";
	long long ans=0;
	if(sum[n]%2==0){
		if(sum[res]==zh){
			if(a[res].ip!=a[res+1].ip){
				ans++;
			}
			a[res+1].x-=1;
			a[res].x-=1;
		}else{
			for(int i=n;i>=res+1;i--){
				a[i+1].ip=a[i].ip;
				a[i+1].x=a[i].x;
			}
			a[res+1].x=sum[res]-(zh+1);
			a[res+1].ip=a[res].ip;
			a[res].x=zh-sum[res-1]-1;
		}
	}else{
		for(int i=n;i>=res+1;i--){
			a[i+1].ip=a[i].ip;
			a[i+1].x=a[i].x;
		}
		a[res+1].x=sum[res]-zh;
		a[res+1].ip=a[res].ip;
		a[res].x=zh-sum[res-1]-1;
	}
	//cout<<ans;
	int st=res,ed=res+1;
	while(st>0&&ed<n+2){
		if(a[st].ip==a[ed].ip){
			if(a[st].x==a[ed].x){
				st--;
				ed++;
			}else if(a[st].x<a[ed].x){
				a[ed].x-=a[st].x;
				st--;
			}else if(a[st].x>a[ed].x){
				a[st].x-=a[ed].x;
				ed++;
			}
		}else{
			if(a[st].x==a[ed].x){
				ans+=a[st].x;
				st--;
				ed++;
			}else if(a[st].x<a[ed].x){
				ans+=a[st].x;
				a[ed].x-=a[st].x;
				st--;
			}else if(a[st].x>a[ed].x){
				ans+=a[ed].x;
				a[st].x-=a[ed].x;
				ed++;
			}
		}
		//cout<<st<<" "<<ed<<"\n";
	}
	cout<<ans;
	return 0;
}
