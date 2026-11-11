#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a!=b){
        cout<<"0000"<<endl;
        return 0;
    }
    int q=(c[0]-'0')*10+c[1]-'0',p=(d[0]-'0')*10+d[1]-'0';
    if(q!=p){
        cout<<"1000"<<endl;
        return 0;
    }
    int m=c[2]-'A',n=d[2]-'A';
    if(m>2&&n<=2||m<=2&&n>2){
        cout<<"1100"<<endl;
        return 0;
    }
    int t=max(m,n),o=min(m,n);
    if(t-o!=1){
        cout<<"1110"<<endl;
        return 0;
    }
    cout<<"1111"<<endl;
    return 0;
}
