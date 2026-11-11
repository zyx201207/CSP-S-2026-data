#include<bits/stdc++.h>
using namespace std;
long long num[105][105];
long long k[105][105];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	long long sum=0;
	cin>>n>>m;
	vector<long long> a;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			num[i][j]=a[j]-a[i];
			k[j-i-1][i]=num[i][j];
		}
	}
	for(int i=0;i<n-1;i++){
		long long temp=m;
		long long ans=1;
		for(int j=0;j<n-1-i;j++){
			if(k[i][j]<=temp){
				temp-=k[i][j];
				ans++;
				if(sum<ans) sum=ans;
			}
		}
	}
	cout<<sum;
	return 0;
} 
