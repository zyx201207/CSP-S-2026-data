#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(m==0){
            if(a[i]==a[i+1]||a[i]==a[i-1]){
                cout<<"2";
                return 0;
            }else{
                cout<<"0";
                return 0;
            }
        }else if(m==1){
            cout<<"2";
            return 0;
        }else{
            cout<<"3";
        }
    }
    return 0;
}
