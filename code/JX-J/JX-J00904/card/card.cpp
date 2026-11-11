#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;
int a[N];
int ans[N];


signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        vector<int> b;
        for(int j=i;j<=n;j++){
            int r=b.size();
            bool fl=0;
            for(int k=0;k<r;k++){
                if(b[k]==a[j]){
                    fl=1;
                    break;
                }
            }
            if(fl){
                while(b[r-1]!=a[j]){
                    b.pop_back();
                    //cout<<"i";
                    r=b.size();
                }
            }

            else {
                b.push_back(a[j]);
                r=b.size();
            }
        }
        for(int j=0;j<b.size();j++)
            ans[b[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
