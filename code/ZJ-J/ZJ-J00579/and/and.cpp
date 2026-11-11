#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int sw[200005][30];
bool canuse[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		canuse[i]=1;
		cin >> a[i];
		for(int j=0;j<30;j++){
			sw[i][j]=a[i]&1;
			a[i]>>=1;
		}
	}
	int ans=0;
	for(int j=29;j>=0;j--){
		for(int i=1;i<=n;i++){
			//cout << sw[i][j] << " " << canuse[i] << endl;
		}
		int num=0;
		for(int i=1;i<=n;i++){
			if(!canuse[i])continue;
			if(sw[i][j]==1){
				num++;
			}
		}
		if(num>=m){
			ans|=(1<<j);
			for(int i=1;i<=n;i++){
				if(sw[i][j]==0)canuse[i]=0;
			}
		}
		//cout << endl;
	}
	cout << ans << endl;
}