#include <bits/stdc++.h>
using namespace std;

long long t;
int n;
int a[200010];
char c[200010];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin>>c[i];
    }
    for(int i=1;i<=n/2;i++){
        if(c[i]!=c[n-i+1]){
            t+=a[i];
    }}
    cout<<t;
    return 0;
}
