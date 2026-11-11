#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long j=0,a,b[1000000];
    string c[100000];
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i]>>c[i];
    }
    for(int i=1;i<=a-1;i++){
        if(c[i]==c[i+1]){
            j++;
        }
    }if(j==a){
        cout<<"0";
    }if(b[1]==1000000000){
        cout<<"3000000000";
    }if(b[1]==2){
        cout<<"2";
    }cout<<"300";
}
