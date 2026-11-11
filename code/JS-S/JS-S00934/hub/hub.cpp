#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc getchar_nolock
#endif
#include <bits/stdc++.h>
using namespace std;

void read(int &x){
    x=0;int f=1;
    char ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=gc();
    }
    x*=f;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int a,b;read(a),read(b);
    cout<<a+b<<endl;

    return 0;
}
