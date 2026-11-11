#include<bits/stdc++.h>
using namespace std;
char c[100001];
long long a[100001];
char s[100001],s1[100001];
int main(){
    long long n,t=0;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];

    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            s1[i]=s[j];
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]!=s1[i]){
            t++;
        }
    }
    cout<<t;
    return 0;
}
