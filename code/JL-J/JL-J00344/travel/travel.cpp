#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        char c[i],s[i];
        cin>>c[i]<<s[i];
        for(int j=i;j<=4;i++){
            if(c[i]=c[j]||s[i]=s[j]){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
    }
    return 0;
}
