#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500100];
int cntt[500100];
int anss=0;
int cnt;
int ttt;
int dj[501000];
bool check(int x){
	if(x<1||x>n){
		return 0;
	}
	int res=0;
	cnt=0;
	int id=upper_bound(a+1,a+n+1,a[x])-a;
	for(int i=id-1;i>=1;i--){
		ttt++;
		res+=(a[x]-a[i]);
		if(res>m){
			break;
		}else{
			cnt++;
		}
	}
	int t=anss;
	if(anss<cnt){
		anss=cnt;
	}
	return cnt>t;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dj[i]=dj[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	if(n<=10000){
		for(int i=1;i<=n;i++){
			check(i);
		}	
		cout<<anss;
		return 0;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(dj[i]<=m){
				ans=max(ans,i);
			}
		}
		cout<<ans;
	}
	return 0;
}