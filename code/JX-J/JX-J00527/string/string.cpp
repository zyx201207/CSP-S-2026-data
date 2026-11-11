#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,a[200001]={},m=0,p=0;
    char l[200001]={},s[200001]={};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>l[i];
        m+=a[i];
    }
    int y=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s[y]=l[i];
            y++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i];
    }
    for(int i=1;i<=m/2;i++){
        if(s[i]!=s[m-i+1]){
            p++;
        }
    }
    cout<<p;
    return 0;
}
