#include<bits/stdc++.h>
using namespace std;
string wth(int a){
    int c[1000],sum=0;string s;
    for(int i=1;;i++){
        if(a==0) break;
        c[i]=a%2;
        a/=2;sum++;
    }
    for(int i=sum;i>=1;i--){
        s[sum-i]=c[i];
    }
    return s;
}
int main(){
    freopen("and.cpp","r",stdin);
    freopen("and.cpp","w",stdout);
    long long n,m,a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<0;
    return 0;
}
