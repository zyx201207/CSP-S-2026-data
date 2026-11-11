#include<bits/stdc++.h>
using namespace std;
long long a[500005];
bool cmp(int a1,int a2){
    return a1<a2;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long sum=1;
    for(int i=1;i<=m;i++){
        sum+=i;
        if(sum>m){
            cout<<i;
            break;
        }
    }
    return 0;
}

