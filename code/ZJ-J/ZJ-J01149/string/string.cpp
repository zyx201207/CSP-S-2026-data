#include<bits/stdc++.h>
using namespace std;
pair<long long,char>a[200005];
pair<long long,long long>id[200005];
long long sum[200005];
long long max(long long a,long long b){
	if(a>=b)return a;
	return b;
}
long long min(long long a,long long b){
	if(a<=b)return a;
	return b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long mid1=0,mid2=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		mid1+=a[i].first;
		sum[i]=sum[i-1]+a[i].first;
		id[i].first=sum[i-1]+1;
		id[i].second=sum[i];
	}
	mid1=mid1/2;
	mid2=sum[n]-mid1;
	long long ans=0;//重复的区间长度 
	long long la=0;//记当前的
	char lc=0;
	long long ra=0;
	char rc=0;
	for(long long l=1,r=n;l<=r;){//双指针
		long long fir=id[l].second;
		long long sec=sum[n]-id[r].first+1;
		long long nl=min(fir,mid1);
		long long nr=min(sec,mid1);
		long long k1=max(0ll,fir-mid1);
		long long k2=max(0ll,sec-mid1);
//		cout<<fir<<" "<<mid1<<" "<<a[l].first<<" "<<k1<<endl;
//		cout<<sec<<" "<<mid1<<" "<<a[r].first<<" "<<k2<<endl;
		long long x=a[l].first;
		long long y=a[r].first;
		a[l].first=x-k1;
		a[r].first=y-k2;
//		cout<<fir<<" "<<mid1<<" "<<a[l].first<<" "<<k1<<endl;
//		cout<<sec<<" "<<mid1<<" "<<a[r].first<<" "<<k2<<endl;
		if(a[l].second==a[r].second){
			ans+=min(a[l].first,a[r].first);
		}
//		cout<<l<<" "<<r<<" "<<nl<<" "<<nr<<" "<<a[l].first<<" "<<a[r].first<<" "<<ans<<endl;
		if(nl<nr){
			a[r].first-=a[l].first;
			l++;
		}else if(nl>nr){
			a[l].first-=a[r].first;
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<mid1-ans;
	return 0;
}
