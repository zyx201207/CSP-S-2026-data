#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],x[200005][33],v[200005],ans,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=30;j++){
			if(a[i]&(1<<(j-1))){
				x[i][j]=1;
			}
		}
	}
	for(int i=30;i>=1;i--){
		ans=0;
		for(int j=1;j<=n;j++){
			if(v[j]==0&&x[j][i]){
				ans++;
			}
		}
		if(ans>=m){
			s+=(1<<(i-1));
			for(int j=1;j<=n;j++){
				if(v[j]==0&&!x[j][i]){
					v[j]=1;
				}
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
