#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int arr[maxn];
int cnt=0;
long long sum[maxn];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(arr[i]-arr[i-1]);
	}
	int r=1,l=2;
	while(r<=n && l<=n){
		if(sum[l]-sum[r-1]<=m){
			cnt=max(cnt,l-r+1);
			l++;
		}else{
			l++;
			r++;
		}
	}
	cout<<cnt;
	return 0;//Oct31==Dec25?
}
