#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
long long n,m,t;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    t=a[0];
    if(m==1){
        cout<<t;
        return 0;
    }
    for(long long i=1;i<m;i++){
        t=t&a[i];
    }
    cout<<t;
    return 0;
}
