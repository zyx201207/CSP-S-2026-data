#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt,maxn,sum;
bool check(int x){
	cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<x){
			cnt+=x-a[i];
			sum++;
		}else if(a[i]==x){
			sum++;
		}
	}
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=a[1],r=a[n];
	while(l<=r){
		int mid=l+(r-l)/2;
		
		if(check(mid)){
			maxn=max(maxn,sum);
		}
		if(cnt<m){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<maxn;
	return 0;
}
