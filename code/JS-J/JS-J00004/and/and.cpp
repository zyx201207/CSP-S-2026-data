#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
bool a[200001][31],b[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//main
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t,c=0;
		cin>>t;
		while(t){
			a[i][++c]=t%2;
			t/=2;
		}
	}
	for(int i=30;i>=1;i--){
		int c=0;
		for(int j=1;j<=n;j++){
			if(!b[j]){
				c+=a[j][i];
			}
		}
		if(c>=m){
			ans+=pow(2,i-1);
			for(int j=1;j<=n;j++){
				b[j]=max(!a[j][i],b[j]);
			}
		}
	}
	cout<<ans;
	cout<<'\n';
	return 0;
}
//70
