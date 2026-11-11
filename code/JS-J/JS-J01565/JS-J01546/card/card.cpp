#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[500005],s1[500005],t[300005];
void fill_(int l,int r){
    for(int i=l;i<=r;i++){
        s1[i] = 0;
    }
    return;
}
void search_(int st){
    for(int i=st;i<=n;i++){
        for(int j=st;j<i;j++){
            if(s1[i]==s1[j]){
                fill_(j,i-1);
            }
        }
    }
    return;
}
int main(){
    /*freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);*/
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s1[i] = s[i];
    }
    for(int i=1;i<=n;i++){
        search_(i);
        for(int j=1;j<=n;j++){
            if(s1[j]!=0&&j>=i){
                t[s1[j]]++;
            }
            s1[j] = s[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
