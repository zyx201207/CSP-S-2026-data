#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
int n,m,a[N],maxn;
void dfs(int las,int k,int ans){
    if (k == m){maxn = max(maxn,ans); return;}
    if (k == 0){
        for (int i = las + 1;i <= n-m+1;i++){
            dfs(i,1,a[i]);
        }
    }
    else {
        for (int i = las + 1;i <= n-m+k+1;i++){
            dfs(i,k+1,(ans & a[i]));
        }
    }
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
    dfs(0,0,0);
    cout << maxn;
    return 0;
}
