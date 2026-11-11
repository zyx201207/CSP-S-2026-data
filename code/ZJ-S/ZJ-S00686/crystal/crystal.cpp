#include<bits/stdc++.h>
#define int long long

using namespace std;
const int e=5e5+10;

int n,m,ans;
int a[e],sum[e];

void read_file(string topic){
	freopen((topic+".in").c_str(),"r",stdin);
	freopen((topic+".out").c_str(),"w",stdout);
	return ;
}

bool check(int pos,int st){
	return (pos-st+1)*a[pos]-(sum[pos]-sum[st-1])<=m;
}

int binarys(int st){
	int l=st,r=n,res=0;
	
	while(l<=r){
		int mid=(l+r)>>1;
		
		if(check(mid,st)){
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	read_file("crystal");

	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	sort(a+1,a+n+1,less<int>());
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
		
	for(int i=1;i<=n;i++)
		ans=max(ans,binarys(i)-i+1);
	
	cout<<ans<<'\n';

	return 0;
}

