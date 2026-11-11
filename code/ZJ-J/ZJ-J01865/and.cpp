#include<bits/stdc++.h>
using namespace std;
const int MAXN = 40;
using b = bitset<MAXN>;
using ull = unsigned long long;
using PII  = pair<int,int>;
b fand(b p,b q){
    b tmp;
    for (int i=0;i<40;i++){
        if ((p[i] == q[i]) &&p[i]){
            tmp[i] =1;
        }
    }
    return tmp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,bitmax=0;
    cin>>n>>m;
    vector<b> tob(n);
    vector<PII> num(n);
    b ans;
    for (int i=0;i<n;i++)
    {
        ull a;
        cin>>a;
        tob[i] = b(a);
        num[i].first = tob[i].count(); num[i].second = i;
        bitmax = tob[bitmax].count() <=num[i].first? i:bitmax;
    }
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    for (auto i : num){
        cout<< i.second<<" "<<i.first <<endl;
    }
    if (m == n){
        for (int i=0;i<n;i++){
            ans = fand(ans,tob[i]);
        }
        cout<<ans.to_ullong();
        return 0;
    }
    else if (m==1){
        ans = tob[bitmax];
        cout<<ans.to_ullong();
        return 0;
    }
    else if (m==2){
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                b tmp;
                tmp = fand(tob[i],tob[j]);
                ans = max(tmp.to_ullong(),ans.to_ullong());
            }
        }
    }
    else{
        int ist=1;
        b tmp,st = tob[num[0].second];
        for (int i=0;i<m;i++){
            for (int j=ist;j<n;j++){
                int id = num[j].second,cnt = num[j].first;
                tmp = fand(st,tob[j]);
                if (tmp.to_ullong()>ans.to_ullong()){
                    ist = j;
                }
            }
            st = tmp;
        }
        ans = tmp;
        cout<<ans.to_ullong();
    }
    return 0;
}
