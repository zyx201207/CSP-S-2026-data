#include<bits/stdc++.h>
using namespace std;
int m,n,a[500010],b[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i];
        b[i]+=a[i-1];
        //cout<<b[i]<<" ";
    }
    //cout<<endl;
    long long ans,l=0,y=n+1,mi;
    bool flag=0;
    while(l<=y){
        mi=(l+y)/2;
        for(int i=1;i<=n-mi;i++){
            //cout<<a[i+mi-1]*mi-b[i+mi-1]+b[i-1]<<" "<<"anw:"<<a[i+mi-1]<<" ";
            if(a[i+mi-1]*mi-b[i+mi-1]+b[i-1]<=m){
                flag=1;
                break;
            }
        }
        //cout<<endl;
        if(flag){
            ans=max(ans,mi);
            l=mi+1;
        }
        else{
            y=mi-1;
        }
    }
    cout<<l;
    return 0;
}
