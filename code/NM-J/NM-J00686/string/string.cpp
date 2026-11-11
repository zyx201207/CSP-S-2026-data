#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int s[1001];
    char z[1001];
    for(int i=0;i<n;i++){
        cin>>s[i]>>z[i];
    }
    if(n==1){
        cout<<"0";
    }else{
        for(int i=0;i<n;i++){
            if(z[i]!=z[i+1]){
                break;
            }
            cout<<"0";
        }
    }


    return 0;
}
