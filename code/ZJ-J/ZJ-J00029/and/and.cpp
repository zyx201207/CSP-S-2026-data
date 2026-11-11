#include<bits/stdc++.h>
using namespace std;
int n,b[35][200005],m;
bool isok[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=30;j>=0;j--){
			if(t>=(1<<j)){
				b[j][i]=1;
				t-=(1<<j);
			}
		}
		isok[i]=1;
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			cnt+=b[i][j]*isok[j];
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				isok[j]&=b[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}