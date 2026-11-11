#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,d,a[N],ans,lt[N][22],rt[N][22],lm;
void MAIN(){
	cin>>n>>d,ans=0;
	lm=__lg(n)+1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=lower_bound(a+1,a+i+1,a[i]-d)-a;
		if(l!=i&&(i==n||a[i+1]-a[l]>d))lt[i][0]=l;
		else lt[i][0]=0;
		int r=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
		if(r!=i&&(i==1||a[r]-a[i-1]>d))rt[i][0]=r;
		else rt[i][0]=0;
//		cout<<l<<" "<<r<<"\n";
	}
	for(int j=1;j<=lm;j++){
		for(int i=1;i<=n;i++){
			lt[i][j]=lt[lt[i][j-1]][j-1];
			rt[i][j]=rt[rt[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<"---------\n"<<i<<"\n";
		int l=lower_bound(a+1,a+i+1,a[i]-d)-a;
//		cout<<l<<"\n";
		if(l==i||l==i-1)continue;
		int ll=lower_bound(a+1,a+l+1,a[l+1]-d)-a;
		int ul=lower_bound(a+1,a+l+1,a[l+2]-d)-a;
//		cout<<ll<<"\n";
		if(ll==l)continue;
		if(ll==ul)continue;
		int tl=1,tr=1;
		if(ll==1||a[l]-a[ll-1]>d){
			for(int j=lm,p=ll;~j;j--)
				if(lt[p][j])p=lt[p][j],tl+=1ll<<j;
		}
		if(i==n||a[i+1]-a[l+1]>d){
			for(int j=lm,p=i;~j;j--)
				if(rt[p][j])p=rt[p][j],tr+=1ll<<j;
		}
//		cout<<ll<<" "<<ul<<" "<<i<<" "<<tl<<" "<<tr<<"\n";
		ans+=(tl+ul-ll-1)*tr;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T>>T;while(T--)MAIN();
	return 0;
}