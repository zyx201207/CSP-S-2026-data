#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[10001]={};
    char b[10001]={};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    string c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            c=c+b[i];
        }
    }
    long long s=0;
    long long m=c.size()/2;
    for(int i=0;i<=m-1;i++){
        if(c[i]!=c[c.size()-1-i]){
            s++;
        }
        else{
            s=s;
        }
    }
    cout<<s;
    return 0;
}
