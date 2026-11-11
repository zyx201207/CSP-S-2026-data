#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 27;

int c , t;
int location[N];
long long dist[10005][10005];
int book[N];

int cnt = 0;


void bfs(int n , int d , int isa , int isb)
{

    int head , tail;
    int disland[N + N] = {0};
    head = tail = 0;

    disland[++tail] = isa;
    book[isa] = 1;

    int min_step = N + N;
    int t[N + N] = {0};

    int step = 0;

    while(head < tail)
    {
        int sisland = disland[head++];

        if(sisland == isb)
        {
            t[step]++;

            min_step = min(step , min_step);
        }

        for(int i = 1; i <= n; i++)
        {
            if(book[i] == 1 || d < dist[sisland][i]) continue;

            disland[++tail] = i;
            book[i] = 1;
        }

        step++;
    }

    if(t[min_step] == 2)
    {
        cnt++;
    }

    return ;

}


int main()
{

    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);

    cin >> c >> t;

    while(t--)
    {
        int n , d;

        cin >> n >> d;

        for(int i = 1; i <= n; i++)
        {
            cin >> location[i];
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = abs(location[j] - location[i]);
            }

            dist[i][i] = 0x3f3f3f;
        }

        int match_islands = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(j >= i) continue;
                else
                {
                    cnt = 0;

                    bfs(n , d , i , j);

                    if(cnt == 2) match_islands++;
                }
            }
        }

        cout << match_islands << endl;
    }



    return 0;


}
