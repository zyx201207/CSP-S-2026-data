#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,ans=1,cnt;
int a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int u=m;
		cnt=1;
		for(int j=i-1;j>=1;j--){
			u-=(a[i]-a[j]);
			if(u>=0){
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout << ans;
//	queue<node>q;
//	q.push({m,a[N]});
//	while(!q.empty()){
//		if(!q.sy==0){
//			ans=max(ans,)
//		}
//		for(int i=1;i<=n;i++){
//			
//		}
//	}
    return 0;
}
