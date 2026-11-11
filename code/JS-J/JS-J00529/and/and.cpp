#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000005];
long long ans,sum;
bool cm(int a,int b){
    return a>b;
}
int main(){
    a[0]=1;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cm);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    for(int i=1;i<=m;i++){
        ans=a[i]&a[i-1];
        if(ans==0){
            m+=1;
        }
    }
    cout<<ans;
    return 0;
}
