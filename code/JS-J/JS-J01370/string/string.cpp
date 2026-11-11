#include <bits/stdc++.h>
using namespace std;
struct cs
{
    int x;
    char c;
};
cs str[200005];
int n;
int l, r;
long long ans =0;

int main()
{
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> str[i].x >> str[i].c;
    }
    l=1;
    r=n;
    while (l<r)
    {
        if (str[l].c == str[r].c)
        {
            if (str[l].x < str[r].x)
            {

                str[r].x -= str[l].x;
                l++;
            }
            else if (str[l].x == str[r].x)
            {
                l++;
                r--;
            }
            else if (str[l].x > str[r].x)
            {

                str[l].x-=str[r].x;
                r--;
            }
        }
        else{
            if (str[l].x < str[r].x)
            {

                str[r].x -= str[l].x;
                ans += str[l].x;
                l++;
            }
            else if (str[l].x == str[r].x)
            {
                ans += str[l].x;
                l++;
                r--;
            }
            else if (str[l].x > str[r].x)
            {

                str[l].x-=str[r].x;
                ans += str[r].x;
                r--;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
