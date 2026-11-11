#include<bits/stdc++.h>
using namespace std;
string n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    long long b=0;
    for(int i=1;i<=a;i++){
        long long x;
        string y;
        cin>>x>>y;
        for(int i=1;i<=x;i++){
            n+=y;
        }
        b+=x;
    }
    long long ans=0;
    for(int i=0;i<b/2;i++){
        if(n[i]!=n[b-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

