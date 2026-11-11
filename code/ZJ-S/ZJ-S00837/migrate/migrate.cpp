#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
int n,d;
int ans=0,end;
void dfs(int num,int nw,int ri,int last){
	if(num!=0&&nw==ri+1)return;
	if(num==0&&nw==ri+1){
		ans++;
		return;
	}
	if(num&&a[nw]-a[last]<=d){
		dfs(num-1,nw+1,ri,nw);
	}
	if(a[nw]-a[last]<=d){
		dfs(num,nw+1,ri,last);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int num=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=num){
				f=0;
			}
		}
		if(f){
			int ans=0;
			for(int i=4;i<=n;i+=2){
				ans+=(n-i+1);
			}
			cout<<ans;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int len=0;
				int num=0;
				for(int k=i+1;k<=j;k++){
					if(len+(a[k]-a[k-1])>d){
						num++;
						len=0;
					}
					len+=(a[k]-a[k-1]);
				}
				if(len)num++;
				ans=0;
				dfs(num,i+1,j,i);
				if(ans==2)end++;
			}
		}
		cout<<end<<endl;
	}
	return 0;
}

