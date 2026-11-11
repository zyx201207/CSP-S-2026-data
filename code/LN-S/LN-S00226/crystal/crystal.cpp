#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    long long s=1,e=n;
    int num=1;
    while(e!=s){
        if(a[e]-a[s]<=m){
            m=m-(a[e]-a[s]);
            num++;
            s++;
        }else e--;
    }
    cout<<num;
    return 0;
}

