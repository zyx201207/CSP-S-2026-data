#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long a[N],m;
void A(){
	long long sum=0,p=0;
	while(sum<=m){
		sum+=p+1;
		if(sum>m){
			break;
		}
		++p;
	}
	cout<<p+1;
	return;
}
void B(int x){
	long long p=0,sum=0;
	while(sum<=m){
		sum+=(p+1)*x;
		if(sum>m){
			break;
		}
		++p;
	}
	cout<<p+1;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int pa=1,pb=1,cha;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			pa=0;
		}
	}
	if(pa==1){
		A();
		return 0;
	}
	cha=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-cha!=a[i-1]) pb=0;
	}
	if(pb==1){
		B(cha);
		return 0;
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long cnt=0,temp=m;
		for(int j=i;j>=1;j--){
			temp-=(a[i]-a[j]);
			if(temp<0){
				break;
			}
			++cnt;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}