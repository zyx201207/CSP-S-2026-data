#include<bits/stdc++.h>
using namespace std;
int f[300001];
int cnt[300001];
int a[500001];
int st[300001];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vec;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];

        if(f[a[i]])
        {
            vec.push_back({f[a[i]], i});
            st[f[a[i]]] = vec.size();
            f[a[i]] = i;
        }
        else
        {
            f[a[i]] = i;
        }
        //f[a[i]] = i;
        //cout << (f[a[i]] = i);

    }
    //for(auto it : vec)
    //{
        //cout << it.first << " " << it.second << '\n';
    //}
    for(int i = 1;i <= n;i ++)
    {
        memset(f, 0, sizeof(f));
        for(int j = i;j <= n;j ++)
        {
            if(st[j])
            {
                j = vec[st[j] - 1].second;
                j --;
            }
            else if(f[j] == 0)
            {
                //cout << "In the " << i << "th game, it leaves " << j << "(" << a[j] << ")behind.\n";
                cnt[a[j]] ++;
                f[i] = 1;
            }
        }
    }
    for(int i = 1;i <= m;i ++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
/*
cin1:

cout1:

cin2:

cout2:

cin3:

cout3:

cin4:

cout4:

cin5:

cout5:

*/
