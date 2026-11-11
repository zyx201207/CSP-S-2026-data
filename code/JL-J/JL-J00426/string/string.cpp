#include<bits/stdc++.h>
using namespace std;
char a[200000005],t[200000005],c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,b,cnt=0,num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b>>c;
        for(int i=0;i<b;i++){
            a[cnt]=c;
            cnt++;
        }
    }
    for(int i=cnt;i>0;i--){
        t[cnt-i]=a[i-1];
    }
    for(int i=0;i<cnt;i++){
        if(a[i]!=t[i]){
            num++;
        }
    }
    cout<<num/2;
return 0;
}
