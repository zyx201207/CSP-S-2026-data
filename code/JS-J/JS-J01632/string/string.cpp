#include <bits/stdc++.h>

using namespace std;

int n;
long long sum[200007];
long long a[200007];
char ch[200007];

void reversed(vector<pair<long long,char> >&A)
{

    vector<pair<long long,char> >B;
    for (int i = A.size() - 1;i >= 0;i--)
    {
        B.push_back(A[i]);
    }
    A = B;
}

void out(vector<pair<long long,char> >A)
{

    for (int i = 0;i < (int)A.size();i++)
    {
        cout << A[i].first << "," << A[i].second << endl;
    }
    cout << endl;
}

/*
3
2 a
2 b
1 c

4
2 a
2 c
3 b
1 d

*/
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> ch[i];
        sum[i] = sum[i - 1] + a[i];
    }
    if (sum[n] % 2 == 1)
    {
        //odd

        long long pos = sum[n] / 2 + 1;
        int idx = 0;

        vector<pair<long long,char> >b(0),c(0);
        //abc

        //1 : aba
        for (int i = 1;i <= n;i++)
        {
            if (!idx && sum[i] >= pos)
            {
                if (sum[i] > pos)
                {
                    if (pos != sum[i - 1] + 1)b.push_back(make_pair(pos - sum[i - 1] - 1,ch[i]));
                    if (sum[i] != pos)c.push_back(make_pair(sum[i] - pos,ch[i]));
                    idx = i - 1;
                }
                else
                {
                    idx = i;
                }
            }
            else if (idx == 0)
            {
                b.push_back(make_pair(a[i],ch[i]));
            }
            else
            {
                c.push_back(make_pair(a[i],ch[i]));
            }
        }
        reversed(c);
        vector<pair<long long,char> >d(0),e(0);
        long long b1 = b[0].first;
        long long c1 = c[0].first;
        for (int i = 0,j = 0;i < (int)b.size() && j < (int)c.size();)
        {
            if (b1 == c1)
            {
                d.push_back(make_pair(b1,b[i].second));
                e.push_back(make_pair(c1,c[j].second));
                i++;j++;
                b1 = b[i].first;
                c1 = c[j].first;
            }
            else if (b1 > c1)
            {
                d.push_back(make_pair(c1,b[i].second));
                e.push_back(make_pair(c1,c[j].second));
                j++;
                b1 -= c1;
                c1 = c[j].first;
            }
            else
            {
                d.push_back(make_pair(b1,b[i].second));
                e.push_back(make_pair(b1,c[j].second));
                i++;
                c1 -= b1;
                b1 = b[i].first;
            }
        }
        long long cnt = 0;
        for (int i = 0;i < (int)d.size();i++)
        {

            if (d[i].second != e[i].second)
                cnt += d[i].first;
        }
        cout << cnt << endl;
    }
    else
    {
        //odd

        long long pos = sum[n] / 2 + 1;

        long long idx = 0;

        vector<pair<long long,char> >b(0),c(0);
        //abc

        //1 : aba
        for (int i = 1;i <= n;i++)
        {
            if (!idx && sum[i] >= pos)
            {
                if (sum[i] > pos)
                {
                    if (pos != sum[i - 1] + 1)b.push_back(make_pair(pos - sum[i - 1] - 1,ch[i]));
                    c.push_back(make_pair(sum[i] - pos + 1,ch[i]));
                    idx = i - 1;
                }
                else
                {
                    idx = i;
                }
            }
            else if (idx == 0)
            {
                b.push_back(make_pair(a[i],ch[i]));
            }
            else
            {
                c.push_back(make_pair(a[i],ch[i]));
            }
        }

        reversed(c);
        //out(b);out(c);
        vector<pair<long long,char> >d(0),e(0);
        long long b1 = b[0].first;
        long long c1 = c[0].first;
        for (int i = 0,j = 0;i < (int)b.size() && j < (int)c.size();)
        {
            //cout << i << " : " << j << " is " << b1 << " " << c1 << endl;
            if (b1 == c1)
            {
                d.push_back(make_pair(b1,b[i].second));
                e.push_back(make_pair(c1,c[j].second));
                i++;j++;

                b1 = b[i].first;
                c1 = c[j].first;
            }
            else if (b1 > c1)
            {
                d.push_back(make_pair(c1,b[i].second));
                e.push_back(make_pair(c1,c[j].second));
                j++;
                b1 -= c1;
                c1 = c[j].first;
            }
            else
            {
                d.push_back(make_pair(b1,b[i].second));
                e.push_back(make_pair(b1,c[j].second));
                i++;
                c1 -= b1;
                b1 = b[i].first;
            }
        }
        //out(d);out(e);
        long long cnt = 0;
        for (int i = 0;i < (int)d.size();i++)
        {

            if (d[i].second != e[i].second)
                cnt += d[i].first;
        }
        cout << cnt << endl;
    }
    return 0;
}
