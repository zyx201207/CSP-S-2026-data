#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,m;
int a[N];
int pre[N];//prefix of sorted a[N]

int get(int l,int r){
	int len=(r-l+1);
	int sum=pre[r]-pre[l-1];
	return len*a[r]-sum;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int longest=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(get(mid,i)<=m){//availible 
				ans=mid;
				r=mid-1;
			}
			else{//not availible
				l=mid+1;
			}
		}
//		cout << ans << '\n';
		longest=max(longest,(i-ans+1));
	}
	cout << longest << '\n';
}
