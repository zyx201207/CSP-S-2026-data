#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[1000000000];
    char qwerty[1000000000];
    long long n,maxn;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>qwerty[i];
    }
    for(int i=0;i<n-1;i++){
        if((qwerty[i]&&qwerty[i+1])!=1){
            break;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        maxn=max(a[i],a[i+1]);
    }
    cout<<maxn;
    return 0;
}
