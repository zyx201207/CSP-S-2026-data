#include<bits/stdc++.h>
using namespace std;
long long a[200001],s[200001];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,s;
	long long sum=1;
	long long ma=INT_MIN,mi=INT_MAX;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long ans=a[0],ans2=a[1],ans3=a[0];
	if(n==m){
		for(int i=1;i<n;i++){
			a[i]&=a[i-1];
		}
		cout<<a[n-1];
	}
	for(int i=0;i<n;i++){
			ma=max(a[i],ma);
			mi=min(a[i],mi);
		}
//  ---------------------
	if(m==1)
	{
		cout<<ma;
	}
//  -----------------------
	if(m==n-1){
		for(int i=1;i<n-1;i++){
			ans&=a[i];
		}
		for(int i=2;i<n;i++){
			ans2&=a[i];
		}
		for(int i=1;i<n;i++){
			if(i==2){
				continue;
			}
			else{
				ans3&=a[i];
			}
		}
		cout<<max(ans,max(ans2,ans3));
	}
	return 0;
}

