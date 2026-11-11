#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[300005],b[300005],c[300005];
vector<int>v;
int main(){
    freopen("card.in","w",stdin);
    freopen("card.out","r",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;i++){
            k=c[j];
            if(!a[k]){
                v.push_back(k);
                a[k]++;
            }
            else{
                a[k]--;
                while(k!=v.front())v.pop_back();
            }
        }
        for(int x=0;x<v.size();x++)b[v[x]]++;
    }
    for(int j=1;j<=m;j++){
        cout<<b[j]<<" ";
    }
    return 0;
}
