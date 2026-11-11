#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long a[N],b[N];

queue<long long> q;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//b[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		//cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	long long ans=1,sum=0,l=1,ans1=1;
	
	for(int i=2;i<=n;i++){
		ans++;
//		sum+=b[i];
		sum+=b[i]*(i-l);
		while(sum>m){
			sum-=(a[i]-a[l]);
			l++;
			ans--;
		}
		ans1=max(ans,ans1);
	}
	cout<<ans1;
	
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 8
-11 -9 -6 -6 -1
*/