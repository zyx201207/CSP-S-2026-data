#include <iostream>
using namespace std;
int a[500000] = {};
int main()
{
    freopen("crystal.in","r",std);
    freopen("crystal.out","w",std);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < n;i ++){
        cin>>a[i];
    }

    int cha[1000] = {};
    int maxx = 0,maxc = 0;
    int tmp;
    for(int i = 2;i <= i - 1;i ++)
    {
        cha[0] = 0;
        cha[1] = a[1] - a[0];
        for(int j = i - 1;j >= 0;j --)
        {
            cha[i] = a[i] - a[j] + cha[i - 1];
            if(cha[i] == m)
            {
                tmp = (i + 1) * a[i];
                if(tmp >= maxx && i + 1 > maxc)
                {
                    maxc = i + 1;
                    maxx = tmp;
                }
            }
        }
    }
    cout<<maxc;
    return 0;
}