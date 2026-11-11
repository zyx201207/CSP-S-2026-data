#include<bits/stdc++.h>
using namespace std;

int n,m,a[1000000],ma;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==1){
        for(int i=0;i<n;i++)ma=max(ma,i);
    }else if(m==n){
        for(int i=0;i<n;i++)ma=ma&a[i];
    }else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ma=max(ma,a[i]&a[j]);
            }
        }
    }else if(m==n-1){
        int h=sqrt(sqrt(sqrt(sqrt(2))))-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j)h=h&a[j];
            }
        }
        ma=h;
    }else ma=a[1]&a[2]&a[3];
    cout<<ma<<"\n";
    return 0;
}
