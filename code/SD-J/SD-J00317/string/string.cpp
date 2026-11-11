#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
char c[200010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int pos,sum=0;
	l/=2;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>=l){
			pos=i;
			break;
		}
	}
	int ans=0,r=n;
	for(int i=1;i<=pos;i++){
		int ned;
		if(i==pos&&sum>l){
			ned=l-(sum-a[i]);
		}else{
			ned=a[i];
		}
		while(ned!=0){
			int f=1;
			if(c[r]==c[i]){
				f=0;
			}
			if(a[r]>ned){
				a[r]-=ned;
				ans+=ned*f;
				ned=0;
			}else if(a[r]==ned){
				a[r]=0;
				ans+=ned*f;
				ned=0;
				r--;
			}else{
				ned-=a[r];
				ans+=a[r]*f;
				a[r]=0;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
