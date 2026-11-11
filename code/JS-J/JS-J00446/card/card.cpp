#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    if(n<=500){
        int idx=0;
        vector<int> ret(m+1);
        for(int i=1;i<=n;i++){
            vector<int> g;
            for(int j=i;j<=n;j++){
                if(find(g.begin(),g.end(),a[j])==g.end()){
                    g.push_back(a[j]);
                }
                else{
                    while(g.back()!=a[j]){
                        g.pop_back();
                    }
                }
            }
            for(int x:g){
                ret[x]++;
            }
        }
        for(int i=1;i<=m;i++)cout<<ret[i]<<' ';
        return 0;
    }

    vector<int> ret(m+1);


    for(int i=1;i<=n;i++){
            bool flag=true;
    int gg=0;
        for(int j=i;j<=n;j++){
            if(a[j]!=gg){
                flag=true;
            }
            if(flag){
                ret[a[j]]++;
                gg=a[j];
                flag=false;
            }

        }
    }
    for(int i=1;i<=m;i++)cout<<ret[i]<<' ';
    return 0;
}
