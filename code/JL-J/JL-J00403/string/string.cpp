#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k=0,t=0;
    long long a[200001];
    char b[200001];
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>a[i]>>b[i];
       k+=a[i];
    }
    if(n==1){
        cout<<"0";
    }
    if(n==2){
        if(a[0]>=a[1]){
           cout<<a[1];
        }
        else{
            cout<<a[0];
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(b[i]==b[i+1]){
                t++;
            }
        }
        if(t==n-1){
            cout<<"0";
        }
        else{
            cout<<k/2;
        }
    }
    return 0;
}

