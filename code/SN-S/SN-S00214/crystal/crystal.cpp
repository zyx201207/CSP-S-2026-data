#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
long long pre[500005];
int n;
long long m;
int out=1;
void confirm(int idx){
	int l=1,r=idx-1,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
        long long cost=1LL*(idx-mid)*arr[idx]-(pre[idx-1]-pre[mid-1]);
        if(cost>m){
        	l=mid+1;
		}
        else{
        	ans=(idx-mid);//°üº¬×Ô¼º 
        	r=mid-1;
		}
	}
	out=max(out,ans);
	//cout<<'\n';
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+arr[i];
	int ans=1;
	for(int i=n;i>=2;i--){
		confirm(i);
	}
	cout<<out+1;
	return 0;
}
