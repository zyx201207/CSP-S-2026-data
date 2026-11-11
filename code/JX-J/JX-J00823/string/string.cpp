#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+10;
string a[N][5];
bool bj=true;
int main(){
    LL n;
    cin>>n;
    string s1[n];
    string s2[n];
    for(LL i=0;i<n;i++){
        for(LL j=0;j<2;j++){
            cin>>a[i][j];

        }
    }
    if(n<=1){
        cout<<"0";
        bj=false;
    }
    else if(n<=2){
        bj=false;
        if(a[0][0]==a[1][0]){
            cout<<"0";
        }
        else{
            cout<<min(a[0][0],a[1][0]);
        }
    }
    for(LL i=0;i<n;i++){
        for(LL j=0;j<2;j++){
            s1[i]=a[i][1];
        }
    }
    for(LL i=n;i>0;i--){
        for(LL j=0;j<2;j++){
            s2[i]=a[i][1];
        }
    }
    LL ans=0;
    for(LL i=0;i<n;i++){
        if(bj==false){
            break;
        }
        if(s1[i]!=s2[i]){
            ans++;
        }
    }
    if(bj==true){
        cout<<ans;
    }
    return 0;
}
