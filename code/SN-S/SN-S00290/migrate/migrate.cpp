#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,ans;
int toy[20];
int a[2000005],n,d,b[200005];
void dfs(int f1,int f2,int cnt){
	if(f1==f2){
		toy[cnt]++;
		return;
	}
	for(int i=f1+1;i<=f2;i++){
		if(a[i]-a[f1]<=d) dfs(i,f2,cnt+1);
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=19;i++){
			toy[i]=0;
		}
		if(c>=1&&c<=6){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(j-i<=2) continue;
					for(int bg=1;bg<=9;bg++){
						toy[bg]=0;
					}
					dfs(i,j,0);
					int cc=0;
					for(int bg=1;bg<=9;bg++){
						if(toy[bg]){
							cc=bg;
							break;
						}
					}
					if(toy[cc]==2){
						ans++;
//						cout<<i<<" "<<j<<" "<<toy[cc]<<" "<<cc<<endl;
					}
				}
			}
			cout<<ans<<endl;
		}
		if(c==11||c==12){
			int x=a[2]-a[1];
			if(d<2*x||d>=3*x){
				cout<<0<<endl;
			}
			else{
				cout<<n-3<<endl;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				a[i]=a[i]-a[i-1];
			}
			for(int i=1;i<=n;i++){
				if(d>=2*a[i]&&d<3*a[i]){
					b[i]=1;
				}
				else if(2*a[i]>d) b[i]=2;
				else b[i]=0;
			}
			int cnt=0;
			int l=1;
			for(int i=4;i<=n;i++){
				if(b[i]==2) l=i+1;
				if(i-l+1>=4) cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
/*
8 3
0 1 2 4 8 10 11 13
0 1 1 2 4 2  1  2
0 0 0 1 2 1  0  0
2
1-4 5-8

6 3
0 1 2 3 4 7
0 1 1 1 1 3
*/
