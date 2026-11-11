#include<bits/stdc++.h>
using namespace std;
int n;
struct s{
    long long g;
    string z;
}a[1000005];
int k=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);



    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].g>>a[i].z;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(a[1].z==a[2].z){
            cout<<0;
            return 0;
        }else{
            if(a[1].g>a[2].g){
                cout<<a[2].g;
                return 0;
            }else{
                cout<<a[1].g;
                return 0;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(a[i].z==a[i+1].z){
            cout<<"";
        }else{
            k=1;
        }
    }
    if(k==0){
        cout<<0;
        return 0;
    }










    return 0;
}
