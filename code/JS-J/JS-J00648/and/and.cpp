#include<bits/stdc++.h>
using namespace std;
int a[200005];
int num[200005];
int res[200005];
int n,m;
long long maxi=0;
void dfs(int d){
    if (d==m+1){
        long long x=num[a[1]];
        for (int i=2;i<=m;i++){
            x = x&num[a[i]];
        }
        maxi = max(maxi,x);
        return;
    }
    for (int i=a[d-1]+1;i<=n;i++){
        a[d] = i;
        dfs(d+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> num[i];
    }
    dfs(1);
    cout << maxi;
    return 0;
}
