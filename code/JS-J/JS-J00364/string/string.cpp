#include <bits/stdc++.h>
using namespace std;
string x;
long long n,a,t=1,s,num;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        num+=a;
        for(int j=1;j<=a;j++){
            x[t]=c;
            t++;
        }
    }
    for(int i=1;i<=num/2+1;i++){
        if(x[i]!=x[num+1-i]) s++;
    }
    cout<<s;
    return 0;
}
