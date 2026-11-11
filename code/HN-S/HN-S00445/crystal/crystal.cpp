#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=7e5;
int a[N],d[N]; 
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int w=0,cnt=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		w+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(w>m){
			w-=a[i]-a[i-cnt+1];
			cnt--;
			
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
// 橙题 
// 14:43 写完 
// 14:46 测试完成，AC。 
