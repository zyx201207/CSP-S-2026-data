#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int l,r;
int a[500005];
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);////////////
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		q[a[i]]++;
	}
	sort(a+1,a+1+n);
	l=1;
	int ans=0,sum=0;
	for(r=1;r<=n;r++){
		int dif=a[r]-a[r-1];
		int lr=r-1;
		sum+=(lr-l+1)*dif;
//		cout<<"//:"<<(lr-l+1)*dif<<endl;
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
//		cout<<l<<' '<<r<<' '<<sum<<endl; 
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;//
}
/*
我们钦定万圣节=圣诞节 
*/ 