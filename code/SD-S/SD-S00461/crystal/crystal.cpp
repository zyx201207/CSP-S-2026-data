#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c[500010],d[500010];
bool check(int x,int t){
	int p=x-t,sum1=t*c[x]; 
	if(sum1-(d[x]-d[p])<=b) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++) cin>>c[i];
	sort(c+1,c+a+1);
	for(int i=1;i<=a;i++) d[i]=d[i-1]+c[i];
	int maxn=1;
	for(int i=1;i<=a;i++){
		int l=1,r=i,ans=1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
