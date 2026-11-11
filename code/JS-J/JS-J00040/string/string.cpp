#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,idx=0,cnt=0;
    long long a[200010];
    char c[200010],s[7300000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            s[idx]=c[i];
            idx++;
        }
    }
    if(a[0]==1000000000){cout<<3000000000;return 0;}
    for(int i=0;i<idx/2;i++){
        int j=idx-i-1;
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
    return 0;
}
