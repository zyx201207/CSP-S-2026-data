#include<bits/stdc++.h>
using namespace std;
bool cmp (int a,int b){
    if(a!=b) return a<b;
}
int main (){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin >>n>>m;
    long long a[n+1];
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a,a+n,cmp);
    int ans=0;
    for(int i=n;i>=2;i--){
        m-=(a[i]-a[i-1]);
        if(m<0) break;
        else ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
