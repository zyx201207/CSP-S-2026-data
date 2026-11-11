#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m;
	vector<long long>a;
	int ans;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	long long c=0;
	int i=0,j=0;
	while(i<n){
		while(c>m){
			c-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
		c+=(a[i+1]-a[i])*(i-j+1);
		i++;
	}
	cout<<ans;
} 
