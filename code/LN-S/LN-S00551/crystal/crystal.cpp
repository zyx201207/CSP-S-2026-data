#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a[n], ans[n],anss;
    cin >> n, m, a[n];
    for(int i = 0;i<=n;i++)
    {
        while(true)
        {
            anss++;
            m--;
            if(anss == a[i]){
                    ans[i] = anss;
            break;
        }
    }
    anss = 0;
    for(int i = 0;i<=n;i++)
    {
        if (anss < ans[i]) anss = ans[i];
    }
    cout anss;
}
