#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+7;
int n,m;
int a[MAXN],ans=1;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int gc=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(m>=i*gc){
			ans++;
			m-=i*gc;
		}else break;
	}
	cout<<min(ans,n);
	return 0;
}
