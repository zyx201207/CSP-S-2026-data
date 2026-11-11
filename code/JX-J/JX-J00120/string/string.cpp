#include<bits/stdc++.h>
using namespace std;
long long n,g=0,p=0,s=0;
char a[100001]={};
char b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>g>>b;
        for(int j=p;j<=p+g;j++){
           a[j]=b;
        }
        p=p+g;
    }
    for(int i=1;i<=p/2;i++){
        if(a[i]!=a[p-i+1]){
            s++;
            cout<<a[i]<<" "<<1<<p<<1<<endl;
        }
    }
    cout<<s;
    return 0;
}
