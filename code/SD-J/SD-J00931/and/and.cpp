#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,t[N],a[N][35],maxwei,pos;
int ans[N],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int cnt=0;
		while(x){
			a[i][++cnt]=x%2;
			x/=2;
		}
		a[i][0]=cnt;
		maxwei=max(maxwei,cnt);
	}
	for(int i=1;i<=n;i++){
		t[i]=1;
	}
	for(int i=maxwei;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(t[j]==0) continue;
			if(a[j][i]==1){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(t[j]==0) continue;
				if(a[j][i]!=1){
					t[j]=0;
				}
			}
			ans[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==1){
			sum=sum+(pow(2,i-1));
		}
	}
	cout<<sum;
	return 0;
}
