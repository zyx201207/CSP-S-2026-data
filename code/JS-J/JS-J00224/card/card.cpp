#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e5 + 10,INF = 0x3f3f3f3f;
bool flag = 0;
int n,m;
int a[N];
vector<int> v;
bool last[N];
int cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        v.push_back(a[i]);
        if(i > 1)flag = (a[i] < a[i - 1]) | flag;
    }

    for(int i = 0;i < v.size();i++){
        vector<int> p;
        for(int j = i;j < v.size();i++){
            auto it = lower_bound(p.begin(),p.end(),v[j]);
            if(it != p.end()){
                p.erase(it,v.begin() + (j - i) - 1);
            }
            p.push_back(v[j]);
        }
        for(int j = 0;j < p.size();j++){
            cnt[p[j]]++;
        }
    }
    for(int i = 1;i <= m;i++)cout << cnt[i] << " ";
    return 0;
}
