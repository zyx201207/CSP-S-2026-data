#include<bits/stdc++.h>
using namespace std;
long long Read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-48;
        c=getchar();
    }
    return f*x;
}
int main(){
    freopen("hab.in","r",stdin);
    freopen("hab.out","w",stdout);

    return 0;
}
