#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    long long tmp;
    while(b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
long long ksl[500005];
char ch[500005];
int kslc[500005];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    memset(ksl, 0, sizeof(ksl));
    memset(ch, 0, sizeof(ch));
    //cout << "=====" << endl;
    cin >> n;
    long long ans = 0;
    int temp = 1;
    for(int i = 1; i <= n; ++i)
    {
        cin >> ksl[temp] >> ch[temp];
        //cout << "===== i = " << i << ", temp = " << temp << ", " << ksl[temp] << ch[temp] << '\n';
        if(ch[temp] == ch[temp - 1])
        {
            ksl[temp - 1] += ksl[temp];
        }
        else
        {
            temp++;
        }
        //cout << "----- i = " << i << ", temp = " << temp << ", " << ksl[temp] << ch[temp] << '\n';
    }
    temp--;
    //cout << flush << "=====" << endl;
    long long tmp = ksl[1];
    int sum = 0;
    for(int i = 2; i <= temp; ++i)
    {
        tmp = gcd(ksl[i], tmp);
    }
    //cout << "===== gcd = " << tmp << endl;
    for(int i = 1; i <= temp; ++i)
    {
        kslc[i] = ksl[i] / tmp;
        sum += kslc[i];
        //cout << "===== ksl[" << i << "] = " << ksl[i] << ", kslc = " << kslc[i] << ", sum = " << sum << '\n';
    }
    //cout << flush << "=====" << endl;
    int l = 1, r = sum;
    int la = 1, lb = 0, ra = temp, rb = kslc[temp];
    char ln, rn;
    while(l < r)
    {
        //cout << "===== l = " << l << ", r = " << r << ", la = " << la << ", lb = " << lb << ", ra = " << ra << ", rb = " << rb << ", ln = " << ch[la] << ", rn = " << ch[la] << ", kslc[la] = " << kslc[la] << ", kslc[ra] = " << kslc[ra] << endl;
        ln = ch[la];
        if(++lb >= kslc[la])
        {
            la++;
            lb = 0;
        }
        rn = ch[ra];
        if(--rb <= 0)
        {
            ra--;
            rb = kslc[ra];
        }
        if(ln != rn)
            ans += tmp;
        l++;
        r--;
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
