//刘曌珩  SN-J00817  西安市含光中学 
#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005][2],b[1005][1005][2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		a[i][1]=1;	
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				a[j][1]=1;
			}
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[j][0]==a[k][0]){
						for(int p=j;p<k;p++){
							a[p][1]=0;
						}
						j=k;
					}
				}
			}
			for(int j=i;j<=n;j++){
				b[i][j][0]=a[j][0];
				b[i][j][1]=a[j][1];
			}
		}
		for(int i=1;i<=m;i++){
			int ans=0;
			for(int j=1;j<=n;j++){
				for(int k=i;k<=n;k++){
					if(b[j][k][1]==1&&b[j][k][0]==i){
						ans++;
					}
				}
			}
			cout<<ans<<" ";
		}
	}
	else{
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
	}
	return 0;
}
