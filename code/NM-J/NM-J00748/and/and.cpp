#include<bits/stdc++.h>
using namespace std;
int a[200100];
bool c[200100][50],b[200100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,i,j,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		int t=a[i];
		for(j=0;j<=30;j++){
			if(t&1) c[i][j]=1;
			t/=2;
		}
	}
	for(j=30;j>=0;j--){
		int sum=0;
		for(i=1;i<=n;i++){
			if(b[i]) continue;
			if(c[i][j]) sum++;
		}
		if(sum>=m){
			ans+=1<<j;
			for(i=1;i<=n;i++){
				if(!c[i][j]) b[i]=1;
			}
		}
	}
	cout<<ans;
	return 0;
} 
