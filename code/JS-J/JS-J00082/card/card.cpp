#include <bits/stdc++.h>
using namespace std;
int n,m;
string a;
char x;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int> sum(m+1);
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        string p=a.substr(i);
        for(int j=0;j<p.size();j++){
            sum[p[j]-'0']++;
        }
    }
    for(int j=1;j<=m;j++){
        cout<<sum[j]<<' ';
    }
    return 0;
}