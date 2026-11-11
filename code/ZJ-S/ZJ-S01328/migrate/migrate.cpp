#include<bits/stdc++.h>
#define int long long 
#define pii pair<int,ll>
#define fi first 
#define se second
using namespace std;
const int N=2010100,B=500,M=501010;
int n,d,c,T,x[N],dp[N][2],nxt[N],pre[N],suf1[N],pre1[N],h[N];
void solve(){
	cin>>n>>d;
	int Ans=0;
	for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=-1,nxt[i]=pre[i]=suf1[i]=pre1[i]=h[i]=0;
	for(int i=1;i<=n;i++)scanf("%lld",x+i);
	if(x[n]-x[1]<=d){
		puts("0");
		return;
	}
	x[n+1]=x[n]+1;
	for(int i=1;i<=n;i++){
		int l=i,r=n,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(x[mid]-x[i]<=d)ans=mid,l=mid+1;
			else r=mid-1;
		}nxt[i]=ans;//cout<<ans<<endl;
	}//cout<<Ans<<endl;
	for(int i=n;i>=1;i--){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(x[i]-x[mid]<=d)ans=mid,r=mid-1;
			else l=mid+1;
		}pre[i]=ans;///cout<<ans<<' ';
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			vector<int>a1,a2;
			a1.clear(),a2.clear();
			int x=i,y=j,op=0;
			while(x<j){
				op=(nxt[x]==x),a1.push_back(x),x=nxt[x];
				if(op)break;
			}a1.push_back(j);
			if(op)continue;
			while(y>i)a2.push_back(y),y=pre[y];
			int cnt=0;a2.push_back(i);
			for(int k=0,l=a2.size()-1;k<a1.size();k++,l--){
			//	cout<<a1[k]<<' '<<a2[l]<<endl;
				cnt+=abs(a1[k]-a2[l]);
			}if(cnt==1)Ans++;//cout<<endl;
		}
	}printf("%d\n",Ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}/*
0 1
10 333333333333333327
-1000000000000000000 
-666666666666666673 
-333333333333333346 
-111111111111111128 
111111111111111090 
 222222222222222199 
333333333333333308 
444444444444444417 
666666666666666635 
999999999999999962
*/

