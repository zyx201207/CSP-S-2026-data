#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],minn=0x3f,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int kkk=n,k=1,minj=minn,flag;
	while(true){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=min(minn,a[j]-a[i]);
				if(minn!=minj){
					flag=i;
					minj=minn;
				}
			}
		}
		a[flag]+=minn;
		if(minn<=m){
			m-=minn;
			ans++;
			minn=0x3f;
			minj=0x3f;
		}
		if(minn>m){
			cout << ans+2;
			return 0;
		}
	}
}
