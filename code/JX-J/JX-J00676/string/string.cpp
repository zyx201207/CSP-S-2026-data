#include<bits/stdc++.h>
using namespace std;
char c[200005];long long a[200005];
long long s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1;i<=n;i++)
    {
        char x;
        long long sum;
        cin >> sum >> x;
        if(x == c[cnt])a[cnt]+=sum;
        else
        {
            c[++cnt] = x;
            a[cnt] = sum;
        }
    }
    for(int i = 1;i<=cnt;i++)s[i] = s[i-1]+a[i];
    //for(int i = 1;i<=cnt;i++)cout << s[i] << " ";
    long long l = 1,r = s[cnt];
    int lid = 1,rid = cnt;
    long long ans = 0;
    while(lid<rid)
    {
  //      cout << l  << " " << lid << " " << r <<  " " << rid << endl;
        long long sl = s[lid]-l+1;
        long long sr = r-s[rid-1];
      //  cout << sl << " " << sr << endl;
        if(sl>sr)
        {
            if(c[rid]!=c[lid])
            {
         //       cout << "*" << endl;
                ans+=sr;
            }
            r = s[rid-1];
            rid--;
            l += sr;

        }
        else if(sl<sr)
        {
            if(c[rid]!=c[lid])
            {
            //    cout << "*" << endl;
                ans+=sl;
            }
            l = s[lid]+1;
            lid++;
            r-=sl;
        }
        else if(sl == sr)
        {
            if(c[rid]!=c[lid])
            {
     //           cout << "*" << endl;
                ans+=sl;
            }
            l = s[lid]+1;
            r = s[rid-1];
            lid++,rid--;
        }
    }
    cout << ans;
    return 0;
}
//aaabbbbcccccceeeddafffwssssa
