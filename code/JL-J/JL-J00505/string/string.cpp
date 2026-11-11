#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s=0,a,qq;
    cin>>n;
    char b;
    string c="";
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
        for(int j=0;j<a;j++){
            c+=b;
        }
    }
    qq=c.size();
    for(int i=0;i<qq;i++){
        if(c[i+qq/2]!=c[qq/2-i]){
            s++;
        }
    }
    cout<<s;
    return 0;
}
