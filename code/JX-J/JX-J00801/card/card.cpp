#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int ll=1;ll<=n;ll++){
        vector<int> v;
        bool tt[500005]={0};
        for(int i=ll;i<=n;i++){
            if(tt[a[i]]){
                while(v[v.size()-1]!=a[i]&&v.size()!=0){
                    tt[v[v.size()-1]]=0;
                    v.pop_back();
                }
                v.pop_back();
            }
            tt[a[i]]=1;
            v.push_back(a[i]);
        }
        for(int i=0;i<v.size();i++){
            t[v[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}
