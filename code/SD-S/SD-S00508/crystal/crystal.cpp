#include<bits/stdc++.h>
#define int long long


using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N];

bool check(int l,int r){
	return a[r]*(r-l)-(pre[r-1]-pre[l-1])<=m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
						//±ðÓÃscanf	 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		if(check(l,i)) ans=max(ans,i-l+1);
//		cout<<l<<" "<<i<<" "<<(a[i]*(i-l)-(pre[i-1]-pre[l-1]))<<"\n";
	}
	cout<<ans;
	return 0;
}
