#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum[200005],cnt=0;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>sum[i]>>c[i],cnt+=sum[i];
	if(cnt%2!=0){
		int ads=0,k=0,m=0;
		for(int i=1;i<=n;i++){
			if(ads<=cnt/2+1&&ads+sum[i]>=cnt/2+1){
				k=i;
				m=cnt/2+1-ads;
				break;
			}
			ads+=sum[i];
		}
		int l=k,r=k,lpos=m-1,rpos=sum[k]-m,ans=0;
		while(l>=1&&r<=n&&(lpos!=0||rpos!=0)){// aabbc
			if(lpos>=rpos){
				if(c[l]!=c[r]) ans+=rpos;
				lpos-=rpos;
				rpos=0;
				r++;
				rpos+=sum[r];
			}
			if(lpos<rpos){
				if(c[l]!=c[r]) ans+=lpos;
				rpos-=lpos;
				lpos=0;
				l--;
				lpos+=sum[l];
			}
		}
		cout<<ans;
	}
	else{
		int ads=0,k=0,m=0;
		for(int i=1;i<=n;i++){
			if(ads<=cnt/2&&ads+sum[i]>=cnt/2){
				k=i;
				m=cnt/2-ads;
				break;
			}
			ads+=sum[i];
		}
		int l=k,lpos=m-1,ans=0,r=0,rpos=0;
		if(m==sum[k]) r=k+1,rpos=sum[k+1]-1,ans++;
		else r=k,rpos=sum[k]-m;
		while(l>=1&&r<=n&&(lpos!=0||rpos!=0)){// aabbc
			if(lpos>=rpos){
				if(c[l]!=c[r]) ans+=rpos;
				lpos-=rpos;
				rpos=0;
				r++;
				rpos+=sum[r];
			}
			else{
				if(c[l]!=c[r]) ans+=lpos;
				rpos-=lpos;
				lpos=0;
				l--;
				lpos+=sum[l];
			}
		}
		cout<<ans;
	}
	return 0;
}
