#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=114514,rp=INT_MAX,maxn=INT_MAX;
int read(){
    int f=1,k=0,c=getchar_unlocked();
    for(;!isdigit(c);c=getchar_unlocked()){
        if(c=='-'){
            f=-1;
        }
    }
    for(;isdigit(c);c=getchar_unlocked()){
        k=k*10+(c^48);
    }
    return f*k;
}
int n;
signed main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    n=read();
    printf("%lld",n);
    return 0;
}

/*ke neng shi zui hou yi ci zai gao zhong da csp le
xi wang yuan meng
wo de oi sheng ya ke bu neng yi zhe zhong fang shi wan jie a
bie le
zhu rp++
*/
