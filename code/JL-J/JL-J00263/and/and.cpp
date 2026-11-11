#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
long long ans=0;
bool zzj(int first,int second){
    return first>second;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n >>m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n,zzj);
    ans=a[1];
    //cout << ans <<endl;
    for(int i=2;i<=m;i++){
            ans=ans&a[i];
            cout <<a[i]<<endl;
    }
    cout <<ans;
    return 0;
}
