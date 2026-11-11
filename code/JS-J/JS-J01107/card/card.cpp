#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
const int inf = 0x3f3f3f3f;

int read(){
    int x = 0,f = 1;char c = getchar_unlocked();
    while(!isdigit(c)){if(c == '-')f = -1;c = getchar_unlocked();}
    while(isdigit(c)){x = x*10 + c-'0';c = getchar_unlocked();}
    return x*f;
}

int a[N],q[N],tl = 0,t[N],d[N];

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n = read(),m = read();
    for(int i = 1;i <= n;i++)a[i] = read();
    for(int i = 1;i <= n;i++){
        tl = 0;
        for(int j = i;j <= n;j++){
            if(d[a[j]] != 0)tl = d[a[j]]-1;
            //for(int i = 1;i <= tl;i++)cout << q[i] << " ";
            //cout << endl;
            q[++tl] = a[j];
            d[a[j]] = tl;
        }
        for(int i = 1;i <= tl;i++)t[q[i]]++;
        for(int i = 1;i <= m;i++)d[i] = 0;
    }
    for(int i = 1;i <= m;i++)cout << t[i] << " ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
