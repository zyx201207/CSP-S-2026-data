#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,maxn;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);
	}
	ans=a[1];
	if(m==1){
		cout << maxn;
		return 0;
	}else if(m==n){
		for(int i = 1;i <= n;i++){
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}else if(m==2){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j<= n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	return 0;
} 
