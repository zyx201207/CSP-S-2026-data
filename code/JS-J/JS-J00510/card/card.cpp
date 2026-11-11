#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int a[300050],b[500050],c[300050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        bool d[300050];
        for(int j=1;j<300050;j++){
            a[j]=0;
            d[j]=0;
        }
        v.clear();
        for(int j=i;j<=n;j++){
            v.push_back(b[j]);
            a[b[j]]++;
            if(a[b[j]]==2){
            v.erase(v.begin()+v.size()-1);
                while(v[v.size()-1]!=b[j]&&v.size()>1){
                    a[v[v.size()-1]]=0;
                    v.erase(v.begin()+v.size()-1);
                }
                a[b[j]]=0;
            }
         }

        for(int j=0;j<v.size();j++){
            d[v[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(d[j]){
                c[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
