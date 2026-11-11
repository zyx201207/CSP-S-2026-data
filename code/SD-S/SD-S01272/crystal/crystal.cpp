#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#define debug(x) cerr<<"debug:"<<__LINE__<<#x<<" "<<x
using namespace std;
const int N=5e5+100,INF=3e18+10;
int n,m,w,a[N],mn=INF,mx=-INF,ans,sum,x;
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x)break;
		cnt+=x-a[i];
	}
	//cout<<cnt<<endl;
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(a[i]!=i)w=1;
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	int l=mn,r=mx;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		//	ans=mid;
		}else{
			r=mid-1;
		}
	}
	ans=l;
//	cout<<ans<<endl;

	for(int i=1;i<=n;i++){
		if(a[i]>ans)break;
		sum++;
	}
	cout<<sum;
	return 0;
}
//5 5 
//1 2 4 8 9
//5 8
//-3 -1 2 2 7

