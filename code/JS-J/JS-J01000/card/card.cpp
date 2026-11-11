#include <bits/stdc++.h>
using namespace std;
int a[500001];
int exist[300001];
int cnt[300001];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w",stdout);
    int n, m;
    vector<int> table;
    for(int i=1;i<=n; i++)cin>>a[i];
    for(int i=1;i<=n; i++){
        for(int j=i;j<=n;j++){
            if (!exist[a[i]]){exist[a[i]]=table.size()+1;table.push_back(a[i]);}
            else {
                for(int k = exist[a[i]]+1; k<=n;k++)table.pop_back();
            }
        }
        for(int j=1;j<=n;j++)cnt[j]+=bool(exist[j]);
        memset(table, 0, table.end()-table.begin());
        memset(exist, 0, 4*n);
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
