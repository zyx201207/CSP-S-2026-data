#include<bits/stdc++.h>
#define ll long long
using namespace std;
int pow2[30];
int n,m,a[200005];
bool c[200005][30];
bool vis[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pow2[0] = 1;
	for(int i = 1;i<30;i++){
		pow2[i] = pow2[i-1]*2;
	}
	for(int i = 0;i<n;i++){
		cin>>a[i];
		int l = a[i];
		for(int j = 29;j>=0;j--){
			if(pow2[j]<=l){
				c[i][j] = 1;
				l-=pow2[j];
			}
		}
	}
	for(int i = 29;i>=0;i--){
		int ans = 0;
		for(int j = 0;j<n;j++){
			if(!vis[j]&&c[j][i]){
				ans++;
			}
		}
		if(ans<m){
			continue;
		}
		if(ans==m){
			for(int j = 0;j<n;j++){
				if(c[j][i]==0){
					vis[j] = true;
				}
			}
			break;
		}
		for(int j = 0;j<n;j++){
			if(c[j][i]==0){
				vis[j] = true;
			}
		}
	}
	int sum = INT_MAX;
	int p = 0;
	for(int i = 0;i<n;i++){
		if(!vis[i]){
			sum &= a[i];
			p++;
			if(p==m){
				break;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
