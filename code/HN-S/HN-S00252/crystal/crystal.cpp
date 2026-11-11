#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long a[n]={};
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long b[n]={};
	for(long long i=0;i<n;i++){
		int c[n]={};
		for(int j=0;j<n;j++){
			c[j]=a[i]-a[j];
		}
		sort(c,c+n,cmp);
		int sum=0;
		for(int j=0;j<n;j++){
			if(sum+c[j]<=m&&c[j]>=0){
				sum+=c[j];
				b[i]++;
			}
		}
	}
	long long maxn=-1;
	for(long long i=0;i<n;i++){
		maxn=max(maxn,b[i]);
	}
	cout<<maxn;
	return 0;
} 
