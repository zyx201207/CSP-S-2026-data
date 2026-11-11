#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,b,e;
    cin>>a;
    string c,d[a];

    for (int i=1;i<=a;i++){
        cin>>b;
        cin>>c;
        d[i]=c;
        if(d[i]!=d[i-1]){
            e+=1;
            d[i]=d[i-1];
        }

    }
    cout<<b*(e-1);
    return 0;
}

