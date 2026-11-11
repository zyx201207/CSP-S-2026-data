#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,card[N],dot[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>card[i];
    for(int i=1;i<=n;i++){
        vector<int> c;
        for(int j=i;j<=n;j++){
            int k=card[j];
            bool f=0;
            for(int q=0;q<c.size();q++){
                if(k==c[q]){
                    f=1;
                    break;
                }
            }
            if(f) while(!c.empty()&&k!=c[c.size()-1]) c.pop_back();
            else c.push_back(card[j]);
        }
        for(int j=0;j<c.size();j++) dot[c[j]]++;
    }
    for(int i=1;i<=m;i++) if(dot[i]!=0) cout<<dot[i]<<" ";
    return 0;
}
