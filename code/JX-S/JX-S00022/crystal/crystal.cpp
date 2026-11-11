#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,num=0,ans=0;
    vector<int> a;
    a.push_back(-999);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=1;i<=n;i++){
        //long long k=1,s=m,d=0;
        long long s=m;
        ans=0;
        for(int j=i-1;j>=1;j--){
            if(s-a[i]+a[j]>0) {ans++;s-a[i]+a[j];}
            else if(s-a[i]+a[j]==0) {ans++;break;}
        }
        if(ans>num) num=ans;
        //else if(ans<num) break;
    }
    cout<<num+1;
    return 0;
}
