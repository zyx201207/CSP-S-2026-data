#include<bits/stdc++.h>
using namespace std;

const int N=2e4+10;
int n,m;
int a[N];
int dp[N][2010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	if(n>20) cout<<a[n];
	if(n<=20){
		for(int x=1;x<=(1<<n)-1;x++){
			//cout<<1;
			int cnt,k;
			for(int i=1;i<=n;i++){
				if(x&(1<<(n-i))){
					//cout<<1;
					if(k==0) cnt=a[i];
					else cnt=cnt&a[i];
					k++;
					//cout<<cnt<<' ';
				}
			}
			//cout<<'\n';
			//cout<<cnt<<' ';
			if(k==m) ans=max(ans,cnt);
		}
		cout<<ans;
	}
	return 0;
}
