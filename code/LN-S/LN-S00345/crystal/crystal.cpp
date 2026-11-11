  #include <bits/stdc++.h>
  using namespace std;
  #define int long long
  int taga (int n,int m,vector <int>& damand);
  int solve (int n,int m,vector <int>& h);
  signed main ()
  {
      ios::sync_with_stdio (false);
      cin.tie (nullptr);
      freopen ("crystal.in","r",stdin);
      freopen ("crystal.out","w",stdout);
      int n,m;
      cin >>n>>m;
      vector <int> a (n,0);
      bool flag=true;
      for (int i=0;i<n;i++)
      {
          cin >>a[i];
          if (a[i]!=i+1) flag=false;
      }
      if (flag)
      {
          int ans;
          ans=taga (n,m,a);
          cout <<ans;
          return 0;
      }
      sort (a.begin (),a.end ());
      vector <int> h (n,0);//前缀和
      for (int i=1;i<(int)a.size ();i++)
      {
          h[i]=h[i-1]+a[i-1];
      }
      int ans;
      ans=solve (n,m,h);
      cout <<ans;
      return 0;
  }
  int taga (int n,int m,vector <int>& damand)
  {
      int cnt=1;
      int ans=1;
      while (cnt<=m)
      {
          ans++;
          cnt+=ans;
          if (ans==n) break;
      }
      return ans;
  }
  int solve (int n,int m,vector <int>& h)
  {
 
      int cnt=-1;//0/1?
    //   vector <int> dp (n,0);
    //   dp[0]=1;
      for (int i=0;i<n;i++)
      {
          int temp=0;
          int cntt=1;
          for (int j=i+1;j<n;j++)
          {
              if (j-i) temp=(h[j]-h[j-1])*(j-i)+temp;
              if (temp<=m)
              {
                  cntt++;
              }
              else
              {
                  break;
              }
          }
          cnt=max (cnt,cntt);
      }
      return cnt;
  }