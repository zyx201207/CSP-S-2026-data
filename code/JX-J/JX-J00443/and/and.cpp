#include <bits/stdc++.h>
using namespace std;
long long ama=INT_MIN,n,m,a[200001]={},tong[1048576]={},ma=INT_MIN;
int main(){
    freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tong[a[i]]++;
        if(a[i]>ma){
            ma=a[i];
        }
    }
    long long b=1;
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
    for(int i=1;i<=ma;i++){
        if(tong[i]!=0){
            a[b]=i;
            b++;
        }
    }
    b--;
    for(int i=1;i<=b;i++){
        for(int j=i+1;j<=b;j++){
            if(a[i]&a[j]>ama){
                ama=a[i]&a[j];
            }
        }
    }
    cout<<ama;
    return 0;
}
