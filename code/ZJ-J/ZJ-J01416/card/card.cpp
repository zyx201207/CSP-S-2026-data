#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N];
int dp[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int x[n],l=1;
		bool y[m];
		for(int j=i;j<=n;j++){
			if(y[a[j]]){
				l--;
				while(y[a[j]]){
					y[x[l--]]=false;
				}x[++l]=a[j];
				y[x[l]]=true;
			}else{
				x[l]=a[j];
				y[x[l]]=true;
			}l++;
		}for(int j=1;j<=m;j++){
			if(y[j])dp[j]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<dp[i]<<' ';
	}
	return 0;
}



