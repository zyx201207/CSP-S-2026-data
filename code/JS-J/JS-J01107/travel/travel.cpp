#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
const int inf = 0x3f3f3f3f;

int read(){
    int x = 0,f = 1;char c = getchar_unlocked();
    while(!isdigit(c)){if(c == '-')f = -1;c = getchar_unlocked();}
    while(isdigit(c)){x = x*10 + c-'0';c = getchar_unlocked();}
    return x*f;
}

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,p1,p2;
    char s1,s2;
    scanf("%lld %lld%c %lld %lld%c",&c1,&p1,&s1,&c2,&p2,&s2);
    if(c1 == c2)cout << 1;
    else cout << 0;
    if(c1 == c2 && p1 == p2)cout << 1;
    else cout << 0;
    if(c1 == c2 && p1 == p2 && ((s1 <= 'C' && s2 <= 'C') || (s1 > 'C' && s2 > 'C')))cout << 1;
    else cout << 0;
    if(c1 == c2 && p1 == p2 && ((s1 <= 'C' && s2 <= 'C') || (s1 > 'C' && s2 > 'C')) && abs(s1-s2) == 1 && (s1 != 'C' || s1 != 'D' || s2 != 'C' || s2 != 'D'))cout << 1;
    else cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
