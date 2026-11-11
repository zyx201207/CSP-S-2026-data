#include<bits/stdc++.h>
using namespace std;
long long n,a,sum;
char b;
string ys;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            ys+=b;
        }
    }
    long long llz=ys.size();
    for(int i=0;i<llz/2;i++){
        if(ys[i]!=ys[llz-i-1])sum++;
    }
    cout<<sum;
    return 0;
}
