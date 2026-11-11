#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
string c[200010],s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    cin>>a[1]>>c[1];

    s=c[1];
    for(int j=1;j<a[1];j++){
        s=s+c[1];
    }
    for(int i=2;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=1;j<=a[i];j++){
            s=s+c[i];
        }
    }
    int f=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=1000000){
            f=1;
        }
    }
    if(f=1){
        long long b=s.size();
        long long cnt=0;
        for(long long i=0;i<b/2;i++){
        if(s[i]!=s[b-i-1]){
            cnt++;
        }
        }
        cout<<cnt;
    }
    else{
        long long g=0;
        for(int i=1;i<=n/2;i++){

            g=g+a[i];
       }
       cout<<g;
    }
    return 0;
}
