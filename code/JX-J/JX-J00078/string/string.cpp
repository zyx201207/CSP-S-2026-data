#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s[10000005];
    char b;
    int n,a,c=0,flag=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s[c+j]=b;
        }
        c+=a;
    }

    for(int i=1;i<=c/2+1;i++){
        if(s[c-i+1]!=s[i]){
            flag++;
        }
    }
    cout<<flag;

    return 0;



}
