#include<bits/stdc++.h>
using namespace std;
string s[10]={"A","B","C","L","T","D","F"};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c,bi,di;
    string b,d;
    cin>>a>>b>>c>>d;
    int e=(b[0]-48)*10+b[1]-48;
    int f=(d[0]-48)*10+d[1]-48;
    b=b[2];
    d=d[2];
    for(int i=0;i<7;i++){
        if(s[i]==b)bi=i;
        if(s[i]==d)di=i;
    }
    cout<<(a==c)?1:0;
    cout<<(e==f&&a==c)?1:0;
    cout<<(abs(bi-di)<=2&&e==f&&a==c)?1:0;
    cout<<(abs(bi-di)==1&&e==f&&a==c)?1:0;
    return 0;
}
