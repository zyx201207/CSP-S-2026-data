#include<bits/stdc++.h>
using namespace std;
int n;
string s;
struct st{
    long long a;
    char c;
}b[200005];
bool f(string ss,long long p){
    string so="";
    for(int i=p-1;i>=0;i--){
        so+=ss[i];
    }
    if(so==ss){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].a>>b[i].c;
        for(int j=1;j<=b[i].a;j++){
            s+=b[i].c;
        }
    }
    long long l=s.size();
    if(f(s,l)){
        cout<<0;
        return 0;
    }
    return 0;
}
