#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
bool v[300005];
vector<int> p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        p.clear();
        memset(v,0,sizeof(v));
        for(int j=i+1;j<=n;j--){
            if(!v[a[j]]){
                p.push_back(a[j]);
                v[a[j]]=1;
            }
            else{
                for(int k=p.size()-1;k>=0;k--){
                    if(p[k]==a[j]){
                        break;
                    }
                    else{
                        v[p[k]]=0;
                        p.pop_back();
                    }
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(v[j]==1){
                b[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    fclose("card.in");
    fclose("card.out");
    return 0;
}
