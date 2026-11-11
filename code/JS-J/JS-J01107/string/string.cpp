#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
const int inf = 0x3f3f3f3f;

int read(){
    int x = 0,f = 1;char c = getchar_unlocked();
    while(!isdigit(c)){if(c == '-')f = -1;c = getchar_unlocked();}
    while(isdigit(c)){x = x*10 + c-'0';c = getchar_unlocked();}
    return x*f;
}

int a[N],len,ans;
char c[N];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n = read(),poi = 1,poj = n,thi = 0,thj = 0,op = 0;
    for(int i = 1;i <= n;i++)a[i] = read(),c[i] = getchar(),len += a[i];
    for(;poi < poj;){//poi,poj wei zhi thi,thj  zhe yi ge zhong yong le ji ge
        if(c[poi] != c[poj])ans += min(a[poi]-thi,a[poj]-thj);
        if(a[poi]-thi > a[poj]-thj)thi += a[poj]-thj,thj = 0,poj--,op = 1;
        else if(a[poi]-thi < a[poj]-thj)thj += a[poi]-thi,thi = 0,poi++,op = 2;
        else if(a[poi]-thi == a[poj]-thj)thi = thj = 0,poi++,poj--,op = 3;
        //cout << poi << " " << poj << " " << thi << " " << thj << " " << ans << endl;
    }
    if(poi == poj){
        if(thi != 0 && poi-1 >= 1 && c[poi-1] != c[poi] && op == 2)ans += a[poi]-thi;
        else if(thj != 0 && poi+1 <= n && c[poi+1] != c[poi] && op == 1)ans += a[poi]-thj;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
