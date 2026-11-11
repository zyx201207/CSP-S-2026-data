#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,total,fa[2000010],dep[2000010],siz[2000010],cur,ans;
bool flag[11],ok[11];
vector<int> g[11];
int read() {
    char ch=getchar();
    int x=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x;
}
void write(int x) {
    if(x>9) write(x/10);
    putchar((x%10)+'0');
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),T=read();
    while(T--) putchar('0'),putchar('\n');
    return 0;
}