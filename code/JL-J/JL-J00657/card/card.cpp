#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int bu[maxn],a[maxn],n,m,nbu[maxn];
vector<int>v;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(nbu[a[j]==1]){
                for(int k=0;k<n;k++){
                    if(v[k]==1){
                        for(int p=k;p<n;p++){
                            v.pop_back();
                        }
                    }
                }
                v.push_back(a[j]);
            }
            else{
                v.push_back(a[j]);
                nbu[a[j]]=1;
            }
        }
        for(int j=0;j<n;j++){
            bu[v[i]]++;
        }
    }
    for(int j=0;j<m;j++){
        cout<<bu[j]<<" ";
    }
    return 0;
}
