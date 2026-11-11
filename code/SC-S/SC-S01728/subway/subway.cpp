#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500002];
int t[502][502];
bool a[502][502];
int cx[4];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int j=1;j<=m;j++)cin>>w[j];
	for(int j=1;j<=n;j++){
		int i,k;
		cin>>i;
		for(int l=1;l<=2*i;l++){//cout<<"asdfgh";
			if(l%2==1){
				cin>>k;
				a[k][j]=1;
			}else{
				cin>>t[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>cx[1]>>cx[2];
		int ans=w[cx[1]]+w[cx[2]];
		for(int j=1;j<=n;j++){
			if(a[cx[1]][j])ans+=t[cx[1]][j];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
