#include <bits/stdc++.h>
using namespace std;
long long n,cnt;
struct no{
    long long a;
    string s;
}p[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)cin >> p[i].a >> p[i].s;
    long long r = 1,l = n;
    while (r < l){
        if (p[r].a < p[l].a && p[r].s != p[l].s)r++,p[l].a -= p[r].a,cnt += p[r].a;
        else if (p[r].a > p[l].a && p[r].s != p[l].s)l--,p[r].a -= p[l].a,cnt += p[l].a;
        else if (p[r].a > p[l].a && p[r].s == p[l].s)l--,p[r].a -=p[l].a;
        else if (p[r].a < p[l].a && p[r].s == p[l].s)r++,p[l].a -= p[r].a;
        else if (p[r].a == p[l].a && p[r].s != p[l].s)cnt += p[l].a,r++,l--;
        else r++,l--;
    }cout << cnt;
    return 0;
}
