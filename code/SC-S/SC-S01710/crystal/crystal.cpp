#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
int a[N],b[N],tot=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int minn=1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			++tot;
			b[tot]=abs(a[i]-a[j]); 
		}
		sort(b+1,b+tot+1);
		int sum=0,cnt=0;
		for(int i=1;i<=tot;i++){
			if(sum>=m){
				break;
			}
			sum+=b[i];
			cnt++;
		}
		if(sum==m){
			minn=min(minn,cnt+1);
		}else{
			minn=min(minn,cnt);
		}
	}
	cout<<minn;
	return 0;
} 
