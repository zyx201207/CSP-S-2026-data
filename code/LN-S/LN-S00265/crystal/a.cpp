#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        //cout <<"i:"  << i <<endl;
        cin>>a[i];
        //cout << "yes!" <<endl;
    }
    sort(a+1,a+n+1);
   for(int i =1;i<=n;i++)
   {
      // cout <<a[i] <<endl;
   }
    int i = 1;
    int j = 1;
    int maax = 0;
     long long anss = 0;
    long long v = 0;
    while(j < n)

    {
//cout << "yes!  "  << i <<endl;
        if(v + (a[j]-a[j-1])*anss<=m)
        {//cout <<"a[i]:" <<a[i] <<"   a[j]" <<a[j]  <<"  "<< a[j] - a[i] << endl;
        //cout << "p1 "  << j <<"ans: " <<anss <<" v: "  <<v <<endl;
//cout <<"!!!!!!" <<v+ (a[j]-a[j-1])*anss  <<"ans : " << anss<< endl;
            v = v+ (a[j]-a[j-1])*anss;
            anss ++;
            //cout << "p2 "  << j <<"ans: " <<anss <<"v:  "  <<v <<endl;
            if(j<=n-1)
            {
               // cout << "ccc";
                 j++;
            }
        }
        else if(v + (a[j]-a[j-1])*anss>m)
        {
            v += (a[j]-a[j-1])*anss;
            int cnt = 1;
            while(v>m && i<j)
            {
               //cout << "  cnt:  "<<cnt << endl;
                cnt++;
                //cout << "NO! "  << j <<"ans:" <<anss <<" v: "  <<v <<endl;
                v-=(a[j] - a[i]);
               // cout << "!!!!" <<a[j] - a[i] <<" v:  " << v <<endl;
                i++;
                anss--;
               //cout << i <<endl;
            }
            anss++;
            j++;
        }
        if(maax<anss)
        {
            maax  =anss;
        }
    }
    cout << maax << endl;
    return 0;
}
