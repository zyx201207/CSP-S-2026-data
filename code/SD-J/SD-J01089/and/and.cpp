#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
bool f[200007];
int q[200]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,16383,32767,65535,131071,262143,524287,1048575};
int a[200007];
int y=0;
bool cmp(int a,int b){
	return a>b;
}
int dfs(int x,int sum){
	if (x>=n&&sum==m){
		int ans=(1<<30)-1;
		for (int i=1;i<=n;i++){
			if (f[i])ans=(ans&a[i]);
		}
		return ans;
	}
	if (x>=n)return 0;
	f[x+1]=1;
	y=max(y,dfs(x+1,sum+1));
	f[x+1]=0;
	y=max(y,dfs(x+1,sum));
	return y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ma=0;
	int f1=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		for (int j=0;j<=20;j++){
			if (a[i]==q[j]){
				f1++;
				break;
			}
		}
		ma=max(ma,a[i]);
	}
	if (m==n){
		int ans=(1<<30)-1;
		for (int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if (m==2){
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}
	else if (m==1){
		cout<<ma;
	}
	else if (ma<=4){
		bool b[4];
		memset(b,0,sizeof(b));
		for (int i=4;i>=0;i--){
			for (int j=1;j<=n;j++){
				if (a[j]==i){
					b[a[j]]=1;
					m--;
				}
				if (m==0&&i>1){
					cout<<i;
					return 0;
				}
				else if (i==1){
					if (b[3]==1){
						cout<<1;
						return 0;
					}
					else{
						int cnt=0;
						for (int k=1;k<=n;k++)if (a[k]==1)cnt++;
						if (cnt>=m){
							cout<<1;
							return 0;
						}
						else{
							cout<<0;
							return 0;
						}
					}
				}
				else {
					cout<<0;
					return 0;
				}
			}
		}
	}
	else if (n<=20){
		f[1]=1;
		y=max(y,dfs(1,1));
		f[1]=0;
		y=max(y,dfs(1,0));
		cout<<y;
	}
	else if (f1==n){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	else cout<<0;
	return 0;
}
