#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[500005];
vector<int> mn;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        mn.clear();
        for(int j=i;j<=n;j++){
            int nn=mn.size();
            if(nn!=0){
                for(int k=0;k<=nn;k++){
                    if(mn[k]==a[j]){
                        for(int kk=k;kk<=nn;kk++)mn[kk]=0;
                        break;
                    }
                }
            }
            mn.push_back(a[j]);
        }
        for(int x:mn) cnt[x]++;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
