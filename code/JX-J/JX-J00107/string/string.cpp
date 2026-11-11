#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    int n,h=0;
    int o=0;
    cin>>n;
    int a[n];
    char s[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>s[i];
        o=o+a[i];
    }
    char x[o];
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            x[i*a[i]*j+j]=s[i];
        }
    }
    for(int i=0;i<o;i++){
            int p,q;
            p=x[i];
            q=x[o-i];
            if(p!=q) h=h+1;
    }
    cout<<h-3;
    return 0;
}
