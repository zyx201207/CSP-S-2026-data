#include<bits/stdc++.h>
using namespace std;
pair<int, int> wei(int a){
    int w = 0, w1 = 0;
    while(a != 0){
        if (a & 1 == 1) w++;
        else w1++;
        a=(a>>1);
    }
    return {w, w1};
}
bool cmp(int a, int b){
    if (wei(a).first != wei(b).first) return wei(a).first>wei(b).first;
    else if (wei(a).second != wei(b).second) return wei(a).second>wei(b).second;
    else return a>b;
}
int n, m, a[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1, cmp);
    int t = INT_MAX;
    for (int i = 1;i<=m;i++){
        t &= a[i];
    }
    cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
