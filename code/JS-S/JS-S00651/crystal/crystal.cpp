#include <bits/stdc++.h>
using namespace std;
long long a[10000006],b[10000006];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    bool flag=true,flag2=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) flag=false;
    }
    int test=a[1]-a[0];
    for(int i=1;i<=n;i++){
        if(a[i]-a[i-1]!=test) flag2=false;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    long long mx=1;
    if(flag){
        for(int i=1;i<=n;i++){
            if(i/2*(i-1)<=m){
                mx=i;
            }
        }
        cout<<mx;
        return 0;
    }
    if(flag2){
        for(int i=1;i<=n;i++){
            if((test+a[i]-1)/2*((a[i]-1-test)/test+1)<=m){
                mx=i;
            }
        }
        cout<<mx;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]*(i-1)-b[i-1]<=m){
            mx=i;
        }
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
