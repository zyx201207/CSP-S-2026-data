#include<bits/stdc++.h>
using namespace std;
string g(int a){
    string s="";
    char c;
    while(a>0){
        c=(a%2)+'0';
        s=c+s;
        a/=2;
    }
    while(s.size()!=30){
        s='0'+s;
    }
    return s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a,x;
    cin>>n>>m;
    string s[n];
    bool f[n];
    for(int i=0;i<n;i++){
        f[i]=true;
        cin>>a;
        s[i]=g(a);
    }
    string ss;
    int res=0;
    for(int i=0;i<30;i++){
        x=0;
        for(int j=0;j<n;j++){
            ss=s[j];
            if(f[j]){
                if(ss[i]=='1') x++;
            }
        }
        if(x>=m){
            res=res*2+1;
            for(int j=0;j<n;j++){
                ss=s[j];
                if(ss[i]=='0') f[j]=false;
            }
        }else res=res*2;
    }
    cout<<res;
    return 0;
}
