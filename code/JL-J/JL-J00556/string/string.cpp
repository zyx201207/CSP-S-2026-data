#include<bits/stdc++.h>
using namespace std;
char a[2000000100];
long long b=0,c=0,e=0,ans=0;
char d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>b;
    for(int i=1;i<=b;i++){
        cin>>c>>d;
        for(int j=e;j<=c+e;j++){
            a[j]=d;
        }
        e+=c;
    }
    for(int i=1;i<=e;i++){
        if(a[i]==a[e-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
