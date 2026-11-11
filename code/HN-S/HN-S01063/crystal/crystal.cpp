#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],pre[N];
int n,m,gongcha;
bool check(int x,int i){
	int zhi=(i-x+1)*(i-x)/2;
	if(zhi<=m){
		return 1;
	}else{
		return 0;
	}
}
bool check2(int x,int i){
	int mo=gongcha*(x-i);
	int xs=x-i+1;
	int zhi=mo*xs/2;
	if(zhi<=m){
		return 1;
	}else{
		return 0;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	bool f=1;
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=1){
			f=0;
			break;
		}
	}
	if(f==1){
		for(int i=n;i>=1;i--){
			int l=1,r=i;
			while(l<=r){
				int mid=(l+r)/2;
				if(check(mid,i)==1){
					r=mid-1;
				}else{
					l=mid+1;
				}
//				cout<<i<<" "<<l<<" "<<r<<endl;
			}
			ans=max(ans,l);
		}
		cout<<ans;
		return 0;
	}
	bool ff=1;
	gongcha=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=gongcha){
			ff=0;
			break;
		}
	}
	if(ff==1){
		for(int i=n;i>=1;i--){
			int l=1,r=i;
			while(l<=r){
				int mid=(l+r)/2;
				if(check2(mid,i)==1){
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			ans=max(ans,l);
		}
		cout<<ans;
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(a[i]-a[i+1]==0)continue;
		int mm=m,cnt=1;
		for(int j=i-1;j>=1;j--){
			mm-=abs(a[i]-a[j]);
			if(mm<0){
				break;
			}
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
