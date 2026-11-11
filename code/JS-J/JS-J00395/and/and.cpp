#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ll n,m;
    cin>>n>>m;
    vector<int>a;
    ll ans=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<m;i++){
        if(i==0){
            ans=a[i]&a[i+1];
             if(m==2){
                    cout<<ans;
                    return 0;
                }
        }
        else{
            int aaa=ans&a[i];
            ans=aaa;
        }
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;

}
