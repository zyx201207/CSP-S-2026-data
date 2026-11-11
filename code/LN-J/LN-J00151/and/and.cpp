#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
int sum1;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            sum1=a[i];
        }
        sum1=(sum1&a[i]);
    }
    bool flag1=0;
    for(int i=1;i<=N;i++){
        int hhh=pow(2,i);
        if(hhh==n){
            flag1=1;
            break;
        }
    }
    sort(a+1,a+n+1,cmp);
    if(n==1){
        cout<<a[1];
    }else if(m==1){
        cout<<a[1];
    }else if(m==n){
        cout<<sum1;
    }else if(flag1){
        cout<<a[m];
    }else{
        cout<<a[m];
    }
    return 0;
}
