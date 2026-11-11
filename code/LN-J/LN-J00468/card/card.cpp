#include<bits/stdc++.h>
using namespace std;

#define int long long
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar();
    }
    return x*f;
}
const int N = 5e5+5;
int n,m;
int a[N], lin[N],d[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    n = read(), m = read();
    if(n>5000&&m>3000){
        for(int i = 1; i <= n; i++){
            a[i] = read();
            if(i!=1&&a[i]!=a[i-1])cout << i-1 << " ";
        }
        cout << n;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i = 1; i <= n; i++){
        a[i]=read();
        d[i]=lin[a[i]];
        lin[a[i]]=i;
    }
    int ans[N]={};
    for(int i = 1; i <= n; i++){
        int lfy[N]={};
        for(int j = i; j <= n; j++){
            if(d[j]==0)lfy[j]=1;
            else{
                if(lfy[d[j]]==1)
                    for(int k = d[j]; k <= j; k++)lfy[k]=0;
                lfy[j]=1;
            }
        }
        for(int j = 1; j <= n; j++)
            if(lfy[j])ans[a[j]]++;
    }
    for(int i = 1; i <= m; i++)printf("%lld ",ans[i]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

