#include <iostream>

using namespace std;

int n,m;
int a[200007],c[200007][32];
bool can[32],choose[200007];
int ans = 0;

void tobin(int x,int k)
{
    int cnt = 0;
    while (x > 0)
    {
        c[k][cnt++] = x % 2;
        x /= 2;
    }
}

/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        tobin(a[i],i);
    }
    for (int i = 1;i <= n;i++)choose[i] = true;
    for (int i = 31;i >= 0;i--)
    {

        int cnt = 0;
        for (int j = 1;j <= n;j++)
        {
            if (choose[j])
            {
                if (c[j][i] == 1)cnt++;
            }
        }
        if (cnt >= m)
        {

            for (int j = 1;j <= n;j++)
            {
                if (choose[j] && c[j][i] == 0)
                {
                    choose[j] = false;
                }
            }
            ans = ans * 2 + 1;
        }
        else{

            ans = ans * 2;
        }
    }
    cout << ans << endl;
    return 0;
}
