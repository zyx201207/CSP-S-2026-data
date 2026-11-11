#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005],an,v[200005],x;
vector<int> b[35];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(), cout.tie();
    freopen("and.in","r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        for (int k = 1; k <= 31; k++)if((a[i]>>(k-1))%2)
            b[k].push_back(i);
    }
    for (int i = 31; i >= 1;i--)if(b[i].size()>=m){
        int k = 0;
        for (int j:b[i])if(v[j]==x)
            k++;
        if(k>=m){
            an += 1 << (i - 1);
            x++;
            for(int j:b[i])
                v[j]++;
        }
    }
    cout << an;
    return 0;
}