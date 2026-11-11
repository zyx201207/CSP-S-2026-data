#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>card(n+1),cnt(m+1,0);
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }for(int i=1;i<=n;i++){
        vector<int>cnt1(m+1,0);
        int first=i;
        for(int j=i;j<=n;j++){
            cnt1[card[j]]++;
            if(cnt1[card[j]]>1){
                first=j;
                for(int k=1;k<=m;k++) cnt1[k]=0;
                cnt1[card[j]]=1;
            }
        }for(int j=first;j<=n;j++){
            cnt[card[j]]++;
        }

    }for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
     return 0;
}
