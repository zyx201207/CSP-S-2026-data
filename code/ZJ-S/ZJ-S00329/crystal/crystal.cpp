#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+100;
int n,ysc=1;
ll m;
ll a[N];
ll sa[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sa[i]=sa[i-1]+a[i];
    int j=1;
    for(int i=1;i<=n;i++){
        while(j<i&&1ll*(i-j+1ll)*a[i]-(sa[i]-sa[j-1])>m)j++;
        ysc=max(ysc,i-j+1);
    }
    cout<<ysc;
    return 0;
}
/*
g++ -std=c++14 -O2 -Wall -o crystal crystal.cpp
time ./crystal<crystal.in>crystal.out
*/