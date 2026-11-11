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
const int N=1e5+10;
int c,t;
int n,d;
int a[N],cnt[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        memset(a,0,sizeof a);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
    }

    return 0;
}
