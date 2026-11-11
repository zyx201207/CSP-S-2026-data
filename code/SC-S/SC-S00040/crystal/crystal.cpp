#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+50;
int n;
int m,k,tag;
int a[MAXN];
int ans,num;
bool check(int x){
	int l=lower_bound(a+1,a+1+n,x)-a;
	num=0;
	for(int i=l;i<=n;i++){
		if(a[i]==x){
			num++;
		}else{
			break;
		}
	}
	k=m;
	for(int i=l-1;i>=1;i--){
		if(k-x+a[i]>=0){
			k-=x-a[i];
			num++;
		}else{
			break;
		}
	}
	if(num>ans){
		ans=num;
		return 1;
	}else{
		return 0;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=a[1];i<=a[n];i++){
			bool p=check(i);
		}
		cout<<ans;
		return 0;
	}
	if(a[2]-a[1]==a[3]-a[2]){
		for(int i=n;i>=1;i++){
			m-=a[i];
			if(m>=0){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	int l=a[1],r=a[n];
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
}