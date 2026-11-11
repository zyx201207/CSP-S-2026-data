#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int idx=0;
    for(int i=1;i<=n;i++){
        idx=0;
        unordered_map<int,int> ump;
        for(int j=i;j<=n;j++){
            if(ump[a[j]]==0){
                ump[a[j]]=idx+1;
                s[++idx]=a[j];
            }
            else{
                idx=ump[a[j]];
            }
        }
        for(int j=1;j<=idx;j++){
            b[s[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
