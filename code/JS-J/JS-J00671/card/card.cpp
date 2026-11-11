#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a[500005];
int c[500005],cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        a[c[i]].push_back(i);
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i+=0){
            int r=0;
            for(int j=0;j<a[c[i]].size()-1;j++){
                if(a[c[i]][j]==i){
                    r=a[c[i]][j+1];
                }
            }
            if(r!=0)i=r;
            else {
                cnt[c[i]]++;
                i++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}

