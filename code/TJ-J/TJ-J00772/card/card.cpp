#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5],ans[m+5];
    for(int i=1;i<=m;i++){
        ans[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        string s="";
        for(int j=i;j<=n;j++){
            s+=char(a[j]);
            for(int k=0;k<s.size()-1;k++){
                if(s[k]==s[s.size()-1]){
                    s=s.substr(0,k);
                    s+=char(a[j]);
                }
            }
        }
        for(int j=0;j<s.size();j++){
            ans[s[j]]++;
        }

    }
    for(int j=1;j<=m;j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}

