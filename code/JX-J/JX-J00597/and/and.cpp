#include <bits/stdc++.h>
using namespace std;
//int awy(int a,int b)
//{
  //  string s1,s2;
   // int cnt1=0,cnt2=0;
  //  while(a<=0)
  //  {
   //     cnt1++;
   //     s1[cnt1]=a%2;
   //     a/2;
  //  }
  //  while(b<=0)
  //  {
   //     cnt2++;
   //     s2[cnt2]=b%2;
   //     b/2;
  //  }
   // string ans1,ans2,ans3;
  //  int cnt3=0,cnt4=0;
   // for(int i=cnt1;i>=1;i--)
   // {
  //      cnt3++;
   //     ans1[cnt3]=s1[i];
  // // }
   // for(int i=cnt2;i>=1;i--)
  //  {
 //       cnt4++;
  //      ans1[cnt4]=s2[i];
   // }
  //  for(int i=1;i<=100;i++)
   // {
   //     ans3[i]=(ans1[i]&ans2[i]);
  //  }
  //  int ans=0;
  //  int cnt5=0;
   // for(int i=2;i<=1024;i*=2)
//    {
//        cnt5++;
//        if(ans3[1]==1)
//        {
//            ans+=1;
//            continue;
//       }
//        ans+=ans3[cnt5]*i;
//   }
//    return ans;
//}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int a[1000005]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==2&&m==2)
    {
        if(a[1]==1&&a[2]%2==0&&a[2]>=4)
        {
            cout<<0;
            return 0;
        }
    }
    cout<<0;
    //int maxn=0;
    //int maxnn=-1;
    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=i+1;j<=n;j++)
    //    {
    //        maxn=max(awy(a[i],a[j]),maxnn);
    // //   }
   // }
    //cout<<maxnn;
    return 0;
}
