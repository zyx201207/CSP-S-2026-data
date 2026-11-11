#include<bits/stdc++.h>
using namespace std;
long long a[100010];
map<int,int>mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }if(m==1){
        cout<<n;
        return 0;
    }else{
        if(a[n]==1){
            cout<<n;
        }
    }
    return 0;
}
