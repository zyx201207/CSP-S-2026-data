#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,n,m,d,q,fd=260300;cin>>c>>n>>m>>d>>q;
	int B[n][fd];
	vector<int>A(m);
	for(int i=0;i<m;i++)cin>>A[i];
	for(int i=0;i<n;i++){
		int k;cin>>k;
		for(int j=0;j<2*k;j++)cin>>B[i][j];
	}
	while(q--){
		int x,y,ans=0;cin>>x>>y;
		ans+=A[x-1]+A[y-1];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){
					if(B[i][0]==x||B[i][2]==x){
						if(B[i][0]==y||B[i][2]==y){
							cout<<ans;
							return 0;
						}
					}
				}else{
					if(B[i][0]==x&&B[j][2]==y){
						if(B[i][2]==B[j][0]){
							ans+=B[i][3]+B[j][1]+B[j][3];
							cout<<ans;
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
}