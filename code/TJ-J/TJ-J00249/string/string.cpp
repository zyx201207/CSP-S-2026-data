#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int mn=min(a[l],a[r]);
		a[l]-=mn;
		a[r]-=mn;
		if(c[l]!=c[r]){
			ans+=mn;
		}
		while(a[l]>0||a[r]>0){
			while(a[l]>0&&l<r){
				r--;
				int mnn=min(a[l],a[r]);
				a[l]-=mnn;
				a[r]-=mnn;
				if(c[l]!=c[r]) ans+=mnn;
			}
			while(a[r]>0&&l<r){
				l++;
				int mnn=min(a[l],a[r]);
				a[l]-=mnn;
				a[r]-=mnn;
				if(c[l]!=c[r]) ans+=mnn;
			}
			if(l>=r){
				cout<<ans;
				return 0;
			}
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
