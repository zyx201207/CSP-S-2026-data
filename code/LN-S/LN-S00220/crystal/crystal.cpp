#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    bool f=false;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i){
            f=true;
        }else
            f=false;
    }
    if(f==true){
        if(m==0||m==1){
            cout<<1;
            return 0;
        }
        else if(m%2!=0){
            if(n<m-1){
                cout<<n;
            }else
                cout<<(1+m+1)/2;
        }
        else if(m%2==0){
            if(n==2){
                cout<<1;
            }
            else if(n<m-1){
                cout<<n;
            }else
                cout<<n/2+1;
        }
    }
    return 0;
}
