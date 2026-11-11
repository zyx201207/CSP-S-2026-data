#include<bits/stdc++.h>
using namespace std;
long long a[500002];
long long m;
int n;
long long maxn=-1;
int cnt=0;
int zh(int x){
	long long l=1,r=n;
	long long mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x && a[mid+1]!=x){
			return mid;
		}
		if(a[mid]<=x){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
int check(long long x){
	long long id=zh(x);
	long long l=id;
	long long ct=m-abs(a[id]-x);
	int cnt=0;
	while(ct>0){
		if(l>=1 && ct-abs(a[l]-x)>=0){
			ct-=abs(a[l]-x);
			cnt++;
		}
		else{
			break;
		}
		l--;
	}
	return cnt;
}
void gotp(){
	int ans=1;
	for(int i=n;i>=1;i--){
		if(m-(a[i]-a[i-1])>=0){
			m-=(a[i]-a[i-1]);
			a[i-1]=a[i];
			ans++;
		}
		else{
			break;
		}
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long tp1=0,tp2=0;
	bool tp=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(i!=1){
			tp1=abs(a[i]-a[i-1]);
		}
		if(tp2!=tp1 && i>2){
			tp=false;
		}
		tp2=tp1;
	}
	sort(a+1,a+1+n);
	if(tp){
		gotp();
		return 0;
	}
	long long l=1,r=maxn+m;
	long long mid=0;
	int sum=0;
	int ans=0;
//	if(r-l>10000){
//		mid=(l+r)/2;
//		ans=check(mid);
//	}
//	while(r-l>10000){
//		mid=mid=(l+r)/2;
//		sum=check(mid);
//		if(sum<ans){
//			r=mid-1;
//		}
//		else{
//			l=mid+1;
//			ans=sum;
//		}
//	}
	for(int i=l;i<=r;i++){
		sum=check(i);//全改为i时，能改几个 
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
