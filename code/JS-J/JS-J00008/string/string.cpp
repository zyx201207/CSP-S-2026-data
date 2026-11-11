#include<bits/stdc++.h>
using namespace std;
long long n,x,pos,cnt;
char c;
string s,si;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        while(x--){
            pos++;
            s[pos]=c;
        }
    }
    si=s;
    for(long long i=1;i<=pos;i++){
        s[i]=s[pos-i];
    }
    for(long long i=1;i<=pos;i++){
        if(s[i]!=si[i]) cnt++;
    }
    cout<<cnt/2;
    return 0;
}
