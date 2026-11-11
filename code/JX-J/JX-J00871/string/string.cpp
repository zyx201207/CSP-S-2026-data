#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n]={};
    char s[n]={};
    for(long long i=0;i<n;i++){
        cin>>a[i]>>s[i];
    }
    //
    char j=s[0];
    int j1=1;
    for(long long i=0;i<n;i++){
        if(s[i]!=j){
            j1=0;
        }
    }
    if(j1==1){
        cout<<0;
        return 0;
    }
    //
    string x;
    for(long long i=0;i<n;i++){
        for(long long k=0;k<a[i];k++){
            x=x+s[i];
        }
    }
    long long cnt=0;
    int f=x.size();
    for(long long i=0;i<=floor(f/2);i++){
        if(x[i]!=x[f-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

