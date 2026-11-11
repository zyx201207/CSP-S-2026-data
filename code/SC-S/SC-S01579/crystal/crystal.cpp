#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int> 
using namespace std;
const int N = 5e5+10, M = 1e5+10,mod=1e9+7;
mt19937 rnd(time(0)); 
int n,m,a[N];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	int ans=0,p=m,now=a[1],l=1,res=0,need=0;
	for(int i=1;i<=n;i++){
		if(now<a[i]){
			int num=i-l;//目前多少个 
			need+=(a[i]-now)*num;
			//if(i==2) cout<<need<<"\n";
			while(l<i){
				if(need<=m) break;
				int sub=a[i]-a[l];
				need-=sub; 
				l++;
				res--;
			}
		}
		now=a[i];
		res++;
		ans=max(ans,res);
		//cout<<res<<" "<<need<<" "<<ans<<"\n"; 
	}
	cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
造：
5 5
1 2 5 8 9

3 
*/