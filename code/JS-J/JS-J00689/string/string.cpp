#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200000];
string b[200000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long cnt=0;
    long long x=0;
    string s="";
    for(long long i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }

    long long l=s.size();
    while (x<=int(l/2-1)){
        if(s[x]!=s[l-1-x]){
            cnt++;
            x++;
    }
        else{
            x++;



        }
    }
    cout<<cnt;
    return 0;
    }
