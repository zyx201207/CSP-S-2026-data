#include<bits/stdc++.h>
using namespace std;
long long t,x;
char c,s[20000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    long long ans=0;
    for(long long i=1;i<=t;i++){
        cin>>x>>c;
        for(long long j=1;j<=x;j++){
            ans++;
            s[ans]=c;
        }
    }
    long long an=0;
    for(long long i=1;;i++){
        if(s[i]!=s[ans]){
            an++;
        }
        if(ans==i+1||ans==i){
            break;
        }
        ans++;    
    }
    cout<<an;
}
