#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10,M = 3e5 + 10;
int n,m;
int a[N],l[M];
bool use[M];
deque<int> de;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }

    for(int j = 1 ;j <= n ; j++)
    {
        for(int i = j ; i <= n ; i++)
        {
            if(!use[a[i]])
            {
                de.push_back(a[i]);
                use[a[i]] = 1;
            }else{
                while(!de.empty())
                {
                    if(de.back()!=a[i])
                    {
                        de.pop_back();
                        use[de.back()] = 0;
                    }
                    if(!de.empty())
                    {
                        de.pop_back();
                        use[de.back()] = 0;
                    }

                }
                de.push_back(a[i]);
            }
        }
        while(!de.empty())
        {
            l[de.back()]++;
            de.pop_back();
        }
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cout << l[i] << " ";
    }

    return 0;
}
