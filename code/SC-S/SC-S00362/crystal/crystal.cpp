#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ll long long
int n,ans;
ll m,a[N],b[N],tot,cnt,temp,x;
bool flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	x=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(i!=1&&a[i]-a[i-1]!=x) flag=0;
		if(i!=1&&a[i]==a[i-1]){
			++b[cnt];
		}else{
			++cnt;
			++b[cnt];
		}
	}
	if(flag){
		int l=1,r=n,mid;
		while(l<=r){
			mid=(l+r)>>1;
			temp=(mid+1)*mid/2*x;
			if(temp<=m){
				ans=mid+1;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<ans;
		return 0;
	}else{
		tot=unique(a+1,a+1+n)-(a+1);
		for(int i=1;i<=tot;i++){
			ll now=0;
			int cnt=b[i];
			for(int j=i-1;j>=1;j--){
				temp=(m-now)/(a[i]-a[j]);
				if(temp>=b[j]){
					now+=b[j]*(a[i]-a[j]);
					cnt+=b[j];
				}else{
					cnt+=temp;
					break;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/