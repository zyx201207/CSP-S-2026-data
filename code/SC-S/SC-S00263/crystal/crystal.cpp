#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long s1[500010];
long long s2[500010];
long long s3[500050];
long long cf[500010];
int n;
long long m;
bool flag=1;
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int j=i+x-2;
		if(s3[j]-s3[i-1]-(i-1)*(s1[j]-s1[i-1])<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s1[1]=a[1];
	for(int i=2;i<=n;i++){
		cf[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<n-1;i++)
		if(cf[i]!=cf[i+1])	flag=0; 
	if(flag){
		int i=1,k=cf[1],ans=1;
		while(m>i*k){
			m-=i*k;
			ans++;
			i++;
		}
		cout<<ans<<endl;
		return 0;
	}
	s1[1]=cf[1];
	for(int i=2;i<n;i++)	s1[i]=s1[i-1]+cf[i];
	for(int i=1;i<n;i++)	s2[i]=i*cf[i];
	s3[1]=s2[1];
	for(int i=2;i<n;i++)	s3[i]=s2[i]+s3[i-1];
	int l=1,r=n,mid=(l+r)/2;
	while(l<=r){
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
		mid=(l+r)/2;
	}
	cout<<mid;
	return 0;
} 