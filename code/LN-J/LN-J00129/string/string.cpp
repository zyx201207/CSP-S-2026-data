#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
long long cnt[N];
char number[N];

int cost = 0;

int main()
{

    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> cnt[i];
        cin >> number[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int hIndex = n - i + 1;

        if(number[i] == number[hIndex])
        {
            if(cnt[hIndex] > cnt[i])
            {
                int nreplace = cnt[hIndex] - cnt[i];

                int Index = i + 1;

                while(nreplace && Index <= n / 2)
                {
                    if(nreplace < cnt[Index])
                    {
                        cost += nreplace;
                        cnt[Index] -= nreplace;
                        break;
                    }

                    nreplace -= cnt[Index];
                    cnt[Index] -= nreplace;
                    cost += nreplace;
                    Index++;
                }
            }
            else
            {
                int nreplace = cnt[i] - cnt[hIndex];

                int Index = hIndex + 1;

                while(nreplace && Index <= n)
                {
                    if(nreplace < cnt[Index])
                    {
                        cost += nreplace;
                        cnt[Index] -= nreplace;
                        break;
                    }

                    nreplace -= cnt[Index];
                    cnt[Index] -= nreplace;
                    cost += nreplace;
                    Index++;
                }
            }
        }
        else
        {
            if(cnt[hIndex] > cnt[i])
            {
                int nreplace = cnt[hIndex] - cnt[i];

                cost += cnt[i];

                int Index = i + 1;

                while(nreplace && Index <= n / 2)
                {
                    if(nreplace < cnt[Index])
                    {
                        cost += nreplace;
                        cnt[Index] -= nreplace;
                        break;
                    }

                    nreplace -= cnt[Index];
                    cnt[Index] -= nreplace;
                    cost += nreplace;
                    Index++;
                }
            }
            else
            {
                int nreplace = cnt[i] - cnt[hIndex];

                cost += cnt[hIndex];

                int Index = hIndex + 1;

                while(nreplace && Index <= n)
                {
                    if(nreplace < cnt[Index])
                    {
                        cost += nreplace;
                        cnt[Index] -= nreplace;
                        break;
                    }

                    nreplace -= cnt[Index];
                    cnt[Index] -= nreplace;
                    cost += nreplace;
                    Index++;
                }
            }
        }
    }







    cout << cost << endl;


    return 0;


}
