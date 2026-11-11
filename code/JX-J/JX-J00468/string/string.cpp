#include<bits/stdc++.h>
using namespace std;
long long  n,a[200005]={0},ls,sum=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=1;i<=n;i++){
        int x;
        char x1;
        cin>>x>>x1;
        for(int j=1;j<=x;j++){
            s+=x1;
        }
    }
    ls=s.size();
    for(int i=1;i<=ls;i++){
        if(s[ls/2+i]!=s[ls/2-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
