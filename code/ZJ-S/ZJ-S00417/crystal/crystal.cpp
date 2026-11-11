#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int N=5e5+5;

int n;
ll m;

ll a[N];

ll d[N],s[N];

bool check(int l,int r){
	return s[r]-s[l-1]-1ll*(r-l+1)*d[r]<=m;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	
//	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	
	for(int i=2;i<=n;i++) d[i]=a[n]-a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+d[i];
	
//	for(int i=1;i<=n;i++) cout<<a[i]<<" "<<d[i]<<" "<<s[i]<<endl;
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(i,mid)) l=mid;
			else r=mid-1;
//			cout<<s[mid]-s[i-1]+(mid-i+1)*d[mid]<<" "<<mid<<"  ";
		}
		
//		cout<<i<<" "<<r<<endl;
		ans=max(ans,r-i+1);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
/*
5 5
1 2 4 8 9
*/
