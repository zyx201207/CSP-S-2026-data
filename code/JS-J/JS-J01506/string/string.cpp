#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin >> a >> c;
        ans+=a;
        for(int j=1;j<=a;j++)
        {
            s=s+c;
        }
    }
    int cnt=0;
  //  if(ans%2==1)
//    {
        for(int i=0;i<(s.size())/2;i++)
        {
            if(s[i]!=s[ans-i-1])cnt++;
        }
  //  }
 //   else{
   //     for(int i=(s.size())/2;i<s.size();i++)
     //   {
       //     if(s[i]!=s[ans-i-1])cnt++;
        //}
   // }
   cout << cnt;
    return 0;
}
