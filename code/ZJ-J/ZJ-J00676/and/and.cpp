#include<iostream>
using namespace std;
int n,m,a,ans;
bool b[200005][35],f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=1;a;a>>=1,j++)b[i][j]=a&1;
	}
	for(int i=30;i>0;i--){
		a=0;
		for(int j=1;j<=n;j++){
			if(!f[j])a+=b[j][i];
		}
		if(a>=m){
			ans+=1<<i-1;
			for(int j=1;j<=n;j++){
				if(!b[j][i])f[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
