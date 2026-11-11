#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 10;
vector<int> a(M),c;
vector<bool> book;
int n,m;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    c.resize(m + 1,0);
    for(int i = 0;i < n;i++)
    {
        book.resize(m + 1,false);
        for(int j = i;j < n;j++)
        {
            if(book[a[j]])
            {
                for(int k = j - 1;k >= i;k--)
                {
                    book[a[k]] = false;
                    if(a[k] == a[j]) break;
                }
                book[a[j]] = true;
            }
            else
            {
                book[a[j]] = true;
            }
        }
        for(int j = 1;j < book.size();j++)
        {
            if(book[j]) c[j]++;
        }
    }
    for(int i = 1;i < c.size();i++) cout<<c[i]<<" ";
    return 0;
}