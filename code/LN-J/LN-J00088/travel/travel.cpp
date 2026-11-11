#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int q=0,w=0,e=0,r=0;
    string a,b,n,m;
    getline(cin,a,n,b,m);
    if(a==b){
        q=1;
    }
    cout<<n%10;
    if(n/10==m/10){
        e=1;
        if((n%10=='A'||n%10=='B'||n%10=='C')&&(m%10=='A'||m%10=='B'||m%10=='C')){
            w=1;
        }else if((n%10=='D'||n%10=='F')&&(m%10=='D'||m%10=='F')){
            w=1;
        }
    }
    if(int(n)-1==int(m)||int(n)+1==int(m)||int(n)==int(m)-1||int(n)==int(m)+1){
        r=1;
    }
    cout<<q<<e<<w<<r;
return 0;
}
