#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[210000],mx=-1,mxb,ans;
int b[210000][50],flag[210000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++){
		int cnt=0;
		while(a[i]>0){
			b[i][++cnt]=a[i]%2;
			a[i]/=2;
		}
		mxb=max(mxb,cnt);
	}
	for(int i=1;i<=n;i++){
		flag[i]=1;
	}
	for(int i=mxb;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			cnt+=b[j][i]*(flag[j]);
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!b[j][i])flag[j]=0;
			}
			ans+=pow(2,i-1);
		}
	}
	cout<<ans;
	return 0;
}