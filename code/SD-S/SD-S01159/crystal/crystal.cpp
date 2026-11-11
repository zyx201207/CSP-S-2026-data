#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long Sum[N];
long long a[N];
int ans=0;
int check(int l,int r){
	long long Cost=0;
	Cost=r-l;
	Cost*=a[r];
	Cost=Cost-Sum[r-1]+Sum[l-1];
	if(Cost<=m)return 1;
	return 0;
}
int Find(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid,x)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return (x-l+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		Sum[i]=Sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,Find(i));
	}
	cout<<ans<<endl;
	return 0;
}
