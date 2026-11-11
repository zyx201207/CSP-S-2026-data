#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y1 y_1
#define f1 first
#define s2 second
const int N=5e5+10;
int n,m,ans;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	bool f=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			f=false;
			break;
		}
	}
	if(f){
		int sum=0;
		for(int i=1;i<=n-1;i++){
			sum+=i;
			if(sum>m){
				ans=i;
				break;
			}
		}
		if(ans==0) ans=n;
		cout<<ans;
		return 0;
	}//A
	f=true;
	int qyr=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=qyr){
			f=false;
			break;
		}
	}
	if(f){
		int sum=0;
		for(int i=1;i<=n-1;i++){
			sum+=(i*qyr);
			if(sum>m){
				ans=i;
				break;
			}
		}
		if(ans==0) ans=n;
		cout<<ans;
		return 0;
	}//B
	for(int i=1;i<=n;i++){
		int w=i+1,sum=0;
		while(true){
			if(w>n){
				ans=max(ans,n-i+1);
				break;
			}
			sum+=(a[w]-a[w-1])*(w-i);
			if(sum>m){
				ans=max(ans,w-i);
				break;
			}
			w++;
		}
	}
	cout<<ans;
	return 0;
}