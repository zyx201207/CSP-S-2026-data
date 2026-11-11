#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m,a[5000005],ans[5000005];
vector<int>desk;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=desk.size();k++){
                if(desk[k]==a[j]){
                    for(int l=k;l<=n;l++){
                       desk.pop_back();
                    }
                    break;
                }
                desk.push_back(a[i]);
            }
        }
        for(int k=1;k<=desk.size();k++){
            ans[desk[k]]++;
        }
        for(int j=1;j<=desk.size();j++){
            desk.pop_back();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
