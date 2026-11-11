#include<bits/stdc++.h>
using namespace std;
char a[1000000010],b,b1=' ';
long long n,m,len=1,ans=0,x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>b;
        if(b!=b1)ans++;
        b1=b;
        for(int j=0;j<=m-1;j++){
            a[len]=b;len++;
        }
    }
    if(ans==1){
        cout<<0;return 0;
    }
    for(int i=1;i<=(len+1)/2;i++){
        if(a[i]!=a[len-i+1])x++;
    }
    cout<<x;
    return 0;
}
