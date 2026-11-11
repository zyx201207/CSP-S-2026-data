#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxm=3e5+5;
int n,m;
int i;
int c[maxm];
vector<int> p[maxm];
int s[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        p[s[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        int k=i;
        while(k!=n+1){
            c[s[k]]++;
            int last=p[s[k]].size()-1;
            k=p[s[k]][last]+1;
        }
    }
    for(int i=1;i<=m;i++){
        cout << c[i];
    }
    return 0;
}
