#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,maxs;
    cin>>n>>maxs;
    int maxsum=0;
    int crystal[500005]={};
    for(int i=1;i<=n;i++)
    {
        cin>>crystal[i];

    }
    int ene=0,cnt=0;
    for(int i=1;i<=n;i++){
        ene+=crystal[i];
        if(ene+1==crystal[i+1])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
