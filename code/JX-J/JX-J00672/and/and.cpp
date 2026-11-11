#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    char s[7000000];
    long long n,m;
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    cout<<a[m];
    return 0;
}
