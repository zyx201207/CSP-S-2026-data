#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    bool b=0;
    long long ans=1,last=0,lasty=1;
    for(auto [x,y]:mp){
        if(b==0){
            last=x;
            b=1;
            continue;
        }
        if((x-last)*lasty>m){
            cout<<ans<<endl;
            break;
        }else{
            ans=y+lasty;
            last=x,lasty+=y;
        }
    }
    cout<<ans<<endl;
    return 0;
}
