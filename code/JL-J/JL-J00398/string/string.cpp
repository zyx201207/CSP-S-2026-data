#include<bits/stdc++.h>
using namespace std;
bool l=1;
int n,a[200001];
string c,b;
string d;
int dfs(int z){
    if(l==1){
        return z;
    }
    l=1;
    for(int i=0;i<n;i++){
        if(a[i]>a[i+1]){
            c[a[i+1]]==c[a[i]];
            z++;
        }
        else{
            c[a[i]]==c[a[i+1]];
        }
        for(int j=n;j>0;j--){
            b[i]==c[i];
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]!=c[i]){
            l=0;
            dfs(z);
        }
    }
    if(l==1){
        return z;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i]>>d[i];
        for(int j=0;j<=a[i];j++){
            c[i]+=d[i];
        }
        for(int j=n;j>0;j--){
            b[i]=c[j];
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=c[i]){
            l=0;
        }
    }
    if(l==1){
        cout<<0;
    }
    else{
        cout<<dfs(0);
    }
    return 0;
}
