#include<bits/stdc++.h>
using namespace std;
long long a=0,b[200001]={},p=0,m[200001]={};
char c[200001]={};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string y="";
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i]>>c[i];
        for(int j=1;j<=b[i];j++){
            y+=c[i];
        }
    }
    for(int i=0;i<y.size()/2;i++){
        if(y[i]!=y[y.size()-i-1]){
            p++;
       }
    }
    cout<<p;
    return 0;

}
