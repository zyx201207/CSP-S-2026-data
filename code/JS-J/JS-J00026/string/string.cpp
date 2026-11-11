#include <bits/stdc++.h>
using namespace std;
int a[20086];
char b[20086];
string s;
int main(){
    freopen("in.string","r",stdin);
    freopen("out.string","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int i=1;i<=a[i];i++){
            s+=b[i];
        }
    }
    int slen=s.size(),num=0;
    for(int i=0;i<=len/2;i++){
        if(a[i]!=a[slen-i-1])num++;
    }
    cout<<num;
    return 0;
 }
