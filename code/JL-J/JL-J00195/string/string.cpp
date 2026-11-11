#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],b=0,e=0;
char d;
string c="",x,y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>d;
        for(int j=1;j<=a[i];j++){
           c=c+d;
        }
    }
    for(int i=0;i<=c.size()/2-1;i++){
       x[i]=c[i];
       cout<<x[i];
    }
    for(int i=c.size()-1;i>=c.size()-c.size()/2;i--){
        y[b]=c[i];
        b++;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<=x.size()-1;i++){
        if(x[i]!=y[i]){
            e++;
        }
    }
    cout<<e;
    return 0;
}
