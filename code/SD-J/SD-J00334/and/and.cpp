#include<bits/stdc++.h>
#define dbg(x) cerr<<"In Line "<<__LINE__<<" , "<<#x<<" = "<<x<<'\n';
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],ans;
int maxx=0,candi=1,larmax=0;
void dfs(int pos,int cnt,int sum){
	if(pos>n){
		if(cnt==m){
			ans=max(ans,sum);
		}
		return ;
	}
	dfs(pos+1,cnt+1,sum&a[pos]);
	dfs(pos+1,cnt,sum);
}
bool cmp(int x,int y){
	int tx=x,ty=y;
	if((tx&larmax)==(ty&larmax))return x>y;
	else return (tx&larmax)>(ty&larmax);
}
 
int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	
	for(int i=1;i<=n;i++){
		int tx=a[i],cntx=0;
		while(tx){
			if(tx&1)cntx++;
			tx>>=1;
		}
		if(cntx>maxx){
			maxx=cntx;
			larmax=a[i];
			candi=i;
		}
		else if(cntx==maxx){
			if(a[i]>larmax){
				larmax=a[i];candi=i;
			}
		}
	}
	int ans=larmax,cnt=0;
	a[candi]=0;m--;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(cnt==m)break;
//		if(a[i]>a[1])continue;
		ans&=a[i];
//		dbg(i);
//		dbg(ans);dbg(cnt);
		cnt++;
	}
	cout<<ans<<'\n';
	return 0;
} 
