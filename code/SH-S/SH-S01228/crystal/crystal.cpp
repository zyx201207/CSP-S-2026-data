#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n,m;
int a[500005];
const int INF=1e5+1;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if (n<=5000){
		int ans=0;
		for (int i=0;i<n;i++){
			int td=a[i],j=i,tm=m,tans=0;
			while(j>=0&&tm>0){ 
				tm-=td-a[j];
				if (tm>=0) tans++;
				j--;
			}
			ans=max(ans,tans);
		}
		cout<<ans<<endl;
	}else{
		int ans=0;
		for (int i=n-1;i<n;i++){
			int td=a[i],j=i,tm=m,tans=0;
			while(j>=0&&tm>0){ 
				tm-=td-a[j];
				if (tm>=0) tans++;
				j--;
			}
			ans=max(ans,tans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
