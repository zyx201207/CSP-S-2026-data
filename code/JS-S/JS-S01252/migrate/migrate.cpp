#include <bits/stdc++.h>
using namespace std;
#define int long long
int read () {
    int s=0,f=1;
    char c=getchar();
    while ((c<'0'||c>'9')&&c!='-') c=getchar();
    if (c=='-') {
        f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9') {
        s=s*10+(c-'0');
        c=getchar();
    }
    return s*f;
}
int c,T;
int n,d;
int x[2000001];
void init () {
    for (int i=1;i<=n;i++) {
        x[i]=0;
    }
    n=read();
    d=read();
    for (int i=1;i<=n;i++) {
        x[i]=read();
    }
}
void work_A () {
    int dis=d/(x[2]-x[1]);
    if (dis==0||dis==1||n-1<=dis) {
        cout<<"0\n";
        return ;
    }
    int temp=2*dis;
    //cout<<n<<' '<<dis<<' ';
    cout<<n-temp+1<<'\n';
}
void work_B () {
    int temp1,temp2;
    for (int i=1;i<=n;i++) {
        if (x[i]-x[1]>d) {
            temp1=i;
            break;
        }
    }
    for (int i=n;i>=1;i--) {
        if (x[n]-x[i]>d) {
            temp2=i;
            break;
        }
    }
    if (temp1-1>temp2) cout<<"0\n";
    else cout<<temp2-temp1+2<<'\n';
}
signed main () {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    T=read();
    while (T--) {
        init();
        if (c==11||c==12) work_A();
        else if (c==13||c==14) work_B();
        else cout<<"0\n";
    }
    return 0;
}