
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,b = 0,d = 0,f = 0;
    char e;
    string c;
    cin >>a;
    for(int i = 0;i<a;i++){
        cin>>b;
        cin>>e;
        b+=d;
        for(int j = d;j<b;j++){
            c[j] = e;

        }
        d=b;
    }
    for(int i = 0;i<d/2;i++){
        if(c[i]!=c[d-i-1])
        f++;
        }
            cout <<f;
    return 0;}
