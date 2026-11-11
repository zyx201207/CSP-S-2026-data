#include<bits/stdc++.h>
using namespace std;
int n=0;
long long a[600000];
char c[200000];
int num=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    long long t=0;
    for (int i=0;i<n;i++){
        t+=a[i];
    }
    cout<<t/2<<endl;
    return 0;
}
