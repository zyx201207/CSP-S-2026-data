#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5;
int dp[N],way[N],a[N],num[N],minn;

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++) a[i]=read();
		if(n<=5000){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) num[j]=0;
				for(int j=i+1;j<=n;j++) dp[j]=2e9,way[j]=0;
				dp[i]=0;way[i]=1;minn=0,num[0]=1;
				for(int l=i,r=i+1;r<=n;r++){
					while(l<=r && a[r]-a[l]>d){
						num[dp[l]]-=way[l];l++;
						if(num[minn]==0) minn++; 
					}
					if(l>r) break;
//					cout<<minn<<" ";
					dp[r]=minn+1,way[r]=num[minn];
					num[minn+1]+=way[r];
				}
//				puts("");
				for(int j=i+1;j<=n;j++){
//					cout<<way[j]<<" ";
					if(way[j]==2) ans++;
				}
//				puts("");
			}
			cout<<ans<<"\n";
		}else puts("0");
	}
	return 0;
}
/*
O(n^2) 是容易的

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1

0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/