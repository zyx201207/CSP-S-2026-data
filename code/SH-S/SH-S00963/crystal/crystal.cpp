#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll INF=0x3f3f3f3f3f3f3f3f;


ll a[N],n,m;
ll pre[N];

bool check(int l,int r,int x){
	int cost=x*(r-l+1)-pre[r]+pre[l-1];
	if(cost>m) return false;
	else return true;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(check(mid,i,a[i])) r=mid;
			else l=mid;
		}
		ans=max(i-r+1,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

