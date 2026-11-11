#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],s[500010];
bool check(int mid,int i){
	int nd=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
	return nd<=m; 
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    freopen("crystal4.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];//
//    cout<<check(1,3)<<endl;
//    return 0;
    int ans=0;
    for(int i=1;i<=n;i++){
    	int l=1,r=i;
    	while(l<r){
    		int mid=l+r>>1;
    		if(check(mid,i))r=mid;
    		else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
    return 0;
}
/*
首先先排序，然后，对于每一个数，计算最多能够有多少个水晶合成0
可以二分答案
 
5 5
1 2 4 8 9

*/