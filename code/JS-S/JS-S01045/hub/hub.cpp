#include <bits/stdc++.h>
using namespace std;

int read(){
    int f=1,res=0;
    char ch; ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        res=res*10+ch-'0';
        ch=getchar_unlocked();
    }
    return res*f;
}



int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);





    return 0;
}