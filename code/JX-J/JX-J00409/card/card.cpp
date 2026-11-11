#include<bits/stdc++.h>
using namespace std;
vector<int> v;
const int N=5*1e5+10;
int num[N],res[N],a[N],n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(num[a[j]]){
                while(v.back()!=a[j]){
                    num[v.back()]--;
                    v.pop_back();
                }
                num[v.back()]--;
                v.pop_back();
            }
            v.push_back(a[j]);
            num[a[j]]++;
        }
        while(!v.empty()){
            res[v.back()]++;
            v.pop_back();
        }
        for(int k=1;k<=m;k++){
            num[k]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<res[i]<<" ";
    }
}
