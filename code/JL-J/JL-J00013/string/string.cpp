#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
long long n;
struct Str{
    long long sum;
    char ch;
}a[N];
bool check(string s)
{
    string p = s;
    reverse(s.begin(),s.end());
    return s == p;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].sum);
        cin>>a[i].ch;
    }
    string s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].sum;j++){
            s += a[i].ch;
        }
    }
    if(check(s)){
        cout<<0;
    }else{
        long long ans = 0;
        int p = 0;
        if(n % 2 == 1) p = s.size() / 2;
        else p = s.size() / 2 - 1;
        for(int i=0;i<=p;i++){
            if(s[i] != s[s.size()-i-1]) ans++;
        }
        cout<<ans;
    }

    return 0;
}
