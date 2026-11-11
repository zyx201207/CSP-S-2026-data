#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m,a[N];
bool use[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,l=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		l&=a[i];
	}
	if(m==1) cout<<mx;
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	if(m==n){
		cout<<l;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

