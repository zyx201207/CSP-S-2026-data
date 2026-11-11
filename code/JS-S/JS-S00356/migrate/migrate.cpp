#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d;
long long x[200005];
long long ansn = 0;

bool ok = 1;

void ans(int l, int r)
{

    if(l + 1 >= r) return;// cout << "l:" << l <<  " r:" << r << "\n";
    long long cnt = 0;
    long long lenn = x[l + 1] - x[l];
   // cout << "ok? " << ok << endl;
    if(ok == 1)
    {
        /*
        if(d % (x[l + 1] - x[l]) != 0) ans += 0;
        else if(d > (x[l + 1] - x[l] ) * 2 - 1 )
        {
            ansn += max(r - ((2 * d -1) * (x[l+1] + x[l])) - l]), 0LL) ;
        }
*/
        long long len = x[l + 1] - x[l];
      //  cout << "len:" << len << "\n";
        if(d >= len * 2 )
        {
            long long num = r - l;
            d =(d / len ) * len;
            ansn += max(num -(2 * d / len) + 1, 0LL);
        //    cout << "ansn:" << ansn << "\n";
        }

    }
  /*  else{
            int cnt = 0;
        for(int i = l;i < r;i++)
        {

            for(int j = l + 1;j < r;j++)
            {

                if(cnt == 0)
                {

                    if(x[j] - x[i] < )
                }
            }
        }
    }*/
    return;
}



void solve()
{
    ansn = 0;
    ok = 1;
    memset(x,0,sizeof(x));
    cin >> n >> d;
  //  cout << n << " " << d << "\n";
    int la = 1;
    cin >> x[1];
    long long l;
    for(int i = 2;i <= n;i++)
    {
        cin >> x[i];
        if(i != 2 && x[i] - x[i - 1] != l) ok = 0;
        //cout << ok << "ok?\n";
        l = x[i] - x[i - 1];
       // cout << "i" << i << " l: " << l << "\n";
        //cout << x[i] << " ";
        if(l > d)
        { ok = 1;
          // cout << "ans" << " \n" ;
            ans(la,i);//[)
            la = i;

        }
        //else cout << "NO" << "\n";
    }
    ans(la,n + 1);
   cout << ansn << "\n";
}

int main()
{
	freopen("migrate.in" ,"r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
