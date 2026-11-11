#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int s[N][35];
int r[35];
int nw=33;
int ans;
int p=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	r[33]=n;
	for(int i=1;i<=n;i++)cin>>s[i][33];
	for(int i=1;i<=30;i++)p*=2;
	for(int i=30;i>=0;i--){
		for(int j=1;j<=r[nw];j++){
			if(s[j][nw]&p){
				s[++r[i]][i]=s[j][nw];
			}
		}
		if(r[i]>=m)ans+=p,nw=i;
		p/=2;
	}
	cout<<ans;
	return 0;
}