#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define srccf ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define N 500007
#define ff first
#define ss seconde

int C,t;
int n,d;
int a[N];
int c[N];
bool fd(int x,int y){
	int now=x,ans=1;
	while(a[y]-a[now]>d){
		now=c[now];
		ans++;
	}
	return ans;
}
int main(){
	srccf;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	if(C==0){ cout<<1<<endl<<2<<endl; return 0; }
	while(t--){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		cin>>n>>d;
		cin>>a[1];
		int l=1;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[l]>d){
				while(a[i]-a[l]>d){
					c[l]=i-1;
					l++;
				}
			}
		}
		while(l<=n){
			c[l]=n;l++;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				int mij=fd(i,j);
				for(int k=i+1;k<=j&&k<=c[i];k++){
					int mkj=fd(k,j);
					if(mkj+1==mij) cnt++;
				}
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//ci=ai-a1+...ai-ai-1
//ci+1=ai+1-ai
//