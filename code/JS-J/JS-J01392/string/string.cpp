#include<bits/stdc++.h>
using namespace std;
string h="";
string s="";
long long a;
void spow(long long x,string y){
    if(x==1) return;
    if(x%2==0){
        h+=h;
    }
    else{
        s+=h;
        h+=h;
    }
    spow(x/2,h);
    return;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n; cin>> n;
    for(long long i=1;i<=n;i++){
        cin>> a >> h;
        spow(a,h);
        s+=h;
    }
    long long k=s.size();
    long long ans=0;
    for(long long i=0;i<k;i++){
        if(s[i]!=s[k-i-1]){
            s[k-i-1]=s[i];
            ans++;
        }
    }
    cout<< ans;
    return 0;
}
