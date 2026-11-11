#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m=0;
    cin>>n>>m;
    long long a[2000000000020]={-1000000000010};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s;
    if(a>0){
        sort(a,a+m+3);
        for(int i=1;i<=n;i++){
            if(a[i]-m+1<0){
                s=i-1;
            }
        }
    }
    if(a<0){
        sort(a,a+m+2);
        for(int i=1;i<=n;i++){
            if(a[i]-m+1<0){
                s=i-3;
            }
        }
    }
    cout<<s;
    return 0;
}
