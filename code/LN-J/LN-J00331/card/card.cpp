#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],t[200001];
vector<int> d;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        d.clear();
        for(int j=i;j<n;j++){
            bool is=0;
            for(int x=0;x<d.size();x++){
                if(d[x]==a[j]){
                    int s=d.size();
                    for(int i=x+1;i<s;i++) d.pop_back();
                    is=1;
                    break;
                }
            }
            if(!is) d.push_back(a[j]);
        }
        for(auto x:d) t[x]++;
    }
    for(int i=1;i<=m;i++) cout<<t[i]<<' ';
}
