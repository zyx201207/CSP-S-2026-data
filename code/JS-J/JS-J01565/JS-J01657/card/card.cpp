#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,m;
int a[N];
map<int,int> ans;
int main(){
    #ifndef YHWDB
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    #endif
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=a[i-1])cnt++;
    }
    cout<<cnt<<endl;
    if(cnt==n){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[j]==a[j-1]&&j-1>=i){
                    continue;
                }else{
                    ans[a[j]]++;
                }
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
    }
    for(int i=1;i<=n;i++){
        vector<int> qe;
        qe.push_back(0);
        for(int j=i;j<=n;j++){
            bool f=0;
            int tar=0;
            for(int k=1;k<qe.size();k++){
                if(qe[k]==a[j]){
                    f=1,tar=k;
                    break;
                }
            }
            for(int k=tar;k<qe.size();k++){
                qe.pop_back();
            }
            qe.push_back(a[j]);
        }
        for(auto t:qe){
            ans[t]++;
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
