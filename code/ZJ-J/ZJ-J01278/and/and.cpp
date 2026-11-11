#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s,sum,q=1;
bool b[200005][30],vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		s=0;
		while(a[i]){
			if(a[i]%2==1) b[i][s]=1;
			a[i]/=2;
			s++;
		}
	}
	for(int i=1;i<=29;i++) q*=2;
	for(int i=29;i>=0;i--){
		s=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if(b[j][i]) s++;
		}
		if(s>=m){
			sum+=q;
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(!b[j][i]) vis[j]=1;
			}
		}
		q/=2;
	}
	cout<<sum;
	return 0;
}
