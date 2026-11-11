#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    if(a!=b) return a>b;
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    long long s=a[0];
    for(int i=1;i<m;i++){
        s=s&a[i];
    }
    cout<<s;
    return 0;
}
