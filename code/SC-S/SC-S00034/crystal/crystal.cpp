#include<bits/stdc++.h>
#define int long long 
using namespace std;

int n,m,a[500010];
int l,r=-INT_MAX,more=0;
int check(int h){//返回达到h需要升级多少次 
	more=0;
	int re=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=h){
			more++;
			re+=h-a[i];
		}
	}
	return re;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r=max(a[i],r);
		l=min(a[i],l);
	}
	int p=1;
	while(l<=r){
		int mid=(l+r)>>1;
		int x=check(mid);
		if(x>m){
			r=mid-1;
		}else{
			l=mid+1;
			p=max(p,more);
		}
	}
	cout<<p;
  return 0;
} 