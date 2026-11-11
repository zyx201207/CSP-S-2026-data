#include<bits/stdc++.h>
using namespace std;
long long n,a,s,l;
char b;
string x,y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a>>b;
        for(int j = 1;j<=a;j++){
            x+=b;
            l++;
        }
    }
    for(int i = l-1;i>=0;i--){
        y+=x[i];
    }
    for(int i = 0;i<l;i++){
        if(x[i]!=y[i]){
            s++;
        }
    }
    cout<<s/2;
    return 0;
}
