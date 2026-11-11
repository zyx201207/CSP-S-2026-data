#include<bits/stdc++.h>
#define int long
using namespace std;
int n,m;
int a[200010]={};
int max1=-1;
bool v[200010]={};
void cs(int s,int sum){
    if(s>=m){
        max1=max(max1,sum);
        return;
    }
    for(int i=0;i<n;i++){
        if(v[i]){
            continue;
        }
        v[i]=1;
        cs(s+1,(sum&a[i]));
        v[i]=0;
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cs(0,pow(2,31)-1);
    cout<<max1;
    //zhushi
    return 0;
}
