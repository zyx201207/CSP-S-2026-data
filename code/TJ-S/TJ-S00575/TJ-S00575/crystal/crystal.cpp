#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[500005];
long long arr[500005];
bool check(int choose){
	long long mistart=1,milast=choose;//-3 -1 2 2 7
	long long midata=s[choose]-s[1];
	for(int i=1;i<=n-choose+1;i++){
		if(s[i+choose-1]-s[i]<midata){
			mistart=i;
			milast=i+choose-1;
			midata=s[i+choose-1]-s[i];
		}
	}
	long long cnt=0;
	for(long long i=mistart;i<milast;i++){
		cnt+=arr[milast]-arr[i];
	}
	if(cnt<=m){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	s[1]=arr[1];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+arr[i];	
	}
	int l=1,r=n;
	int cnt=0;
	while(l<r){
		int sum=(l+r)/2;
		if((l+r)%2!=0){
			//cout<<sum;
			sum++;
		}
		if(check(sum)){
			l=sum;
		}
		else{
			r=sum-1;
		}
		//cout<<sum<<" "<<r<<" "<<l<<endl;
		//cnt++;
	}
	cout<<l;
	return 0;
}
