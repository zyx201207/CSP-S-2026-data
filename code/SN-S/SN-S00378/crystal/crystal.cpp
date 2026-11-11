//姓名：刘浩宇  学校：西安市汇知中学  考号：SN_S00378 
#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false);
using namespace std;
int n,m,a[500005],b[500005],ans;
bool check(int x,int y){
	return a[y]*(y-x+1)-b[y]+b[x-1]<=m;
}
signed main(){
	IOS
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
