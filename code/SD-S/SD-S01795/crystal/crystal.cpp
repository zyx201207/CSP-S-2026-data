#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,m;
long long cha[500005];
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int fa=0,fb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(abs(a[1]-a[2])<=m){
			cout<<2;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	long long gc=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			fa=1;
		}
		if((a[i]-a[i-1])!=gc){
			fb=1;
		}
	}
	if(fa==0){
		int t=1;
		long long temp=0;
		int an=0;
		while(1){
			t++;
			temp=t*(t-1)/2;
			if(temp>m){
				an=t-1;
				break;
			}
		}
		cout<<an;
		return 0;
	}
	if(fb==0){
		int t=1,as=0;
		long long temp=0;
		while(1){
			t++;
			temp=(gc*t)*(t-1)/2;
			if(temp>m){
				as=t-1;
				break;
			}
		}
		cout<<as;
		return 0;
	}
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		sum[i]=cha[i]+sum[i-1];
	}
	long long ans=0;
	for(int i=2;i<=n;i++){
		long long k=i-1,pos=0,cnt=1;
		for(int j=k;j>=1;j--){
			if((sum[i]-sum[j]+pos)<=m){
				pos=sum[i]-sum[j]+pos;
				cnt++;
			}
			else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
