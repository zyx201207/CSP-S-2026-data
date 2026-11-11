#include<bits/stdc++.h>
using namespace std;
int n, np, m, a[500010], cnt[500010];
string s;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    while(np<n){
        s.clear();
        for(int i=np; i<n; i++){
                if(0<=s.find(a[i]) && s.find(a[i])<=n){
                    for(int j=s.find(a[i]); j<=s.size(); j++){
                        s[j]=0;
                    }
                }
            s+=a[i];
        }
        for(int i=0; i<s.size(); i++){
            cnt[s[i]]++;
        }
        np++;
    }
    for(int i=1; i<=m; i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
