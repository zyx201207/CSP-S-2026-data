#include<bits/stdc++.h>
using namespace std;
char a[2000000];
char f[2000000];
char g[2000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long b,c;
    cin>>b;
    char d;
    long long e=0;
    long long m=0;
    for(int i=0;i<b;i++){
        cin>>c>>d;
        for(int j=0;j<c;j++){
            a[e]=d;
            e++;
        }
    }

    for(long long i=0;i<e/2;i++){
        f[i]=a[i];
    }
    for(long long i=0;i<e/2;i++){
        g[i]=a[e-1-i];
    }
    for(long long i=0;i<e/2;i++){
        if(g[i]!=f[i]){
            m++;
        }
    }
    cout<<m;
    return 0;
}
