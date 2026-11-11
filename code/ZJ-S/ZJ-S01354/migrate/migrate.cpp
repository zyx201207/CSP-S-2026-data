#include<bits/stdc++.h>
using namespace std;
int n;
long long d,x[2000010];
int l[2000010],r[2000010],nxt1[2000010],nxt2[2000010],cnt1[2000010],cnt2[2000010];
//倍增？
int main()
{freopen("migrate.in","r",stdin);
 freopen("migrate.out","w",stdout);
 ios::sync_with_stdio(0);cin.tie(0);
 int cc,t;cin>>cc>>t;
 while(t--)
 {cin>>n>>d;
  for(int i=1;i<=n;i++) cin>>x[i];
  int j=1;
  for(int i=1;i<=n;i++)
  {while(x[j+1]-x[i]<=d&&j!=n) j++;
   r[i]=j;
  }
  j=n;
  for(int i=n;i>=1;i--)
  {while(x[i]-x[j-1]<=d&&j!=1) j--;
   l[i]=j;
  }
  for(int i=1;i<n;i++) cnt1[i]=cnt2[i]=0;
  //考察每个对有多少唯一路径
  for(int i=n-1;i>=1;i--)
  {//[r[i]+1,r[i+1]]
   if(r[i]==r[i+1]||r[i+1]==i+1) nxt1[i]=0;
   else nxt1[i]=(r[i+1]-r[i])+nxt1[r[i+1]-1];
  }
  for(int i=1;i<n;i++)
  {if(l[i]==l[i+1]||l[i]==i) nxt2[i]=0;
   else nxt2[i]=(l[i+1]-l[i])+nxt2[l[i]];
  }
  for(int i=2;i<n;i++)
  if(r[i]-r[i-1]&&r[i]>i+1) cnt1[i]=r[i]-r[i-1]+(r[i]==r[i+1])*nxt1[r[i]-1];
  for(int i=n-2;i>=1;i--)
  if(l[i+2]-l[i+1]&&l[i+1]<i) cnt2[i]=l[i+2]-l[i+1]+(l[i]==l[i+1])*nxt2[l[i+1]];
  //for(int i=1;i<n;i++) cout<<nxt1[i]<<' '<<nxt2[i]<<'\n';
  //for(int i=1;i<n;i++) cout<<cnt1[i]<<' '<<cnt2[i]<<'\n';
  //可行等价类？？？
  //处理无分歧路线
  //corner 走不远，废
  /*for(int i=n;i>=1;i--)
  {if(r[i]==i||r[i]==n) {nxt1[i]=n+1;continue;}
   if(r[r[i]]==r[r[i]-1])
   {if(r[i]-2>i) if(r[r[i]]==r[r[i]-2]) {nxt1[i]=n+1;continue;}
    cnt1[r[i]-1]++;nxt1[i]=r[i]-1;
    //临时改r！
    //r[i]=r[i]-1;
   }
   else
   {nxt1[i]=nxt1[r[i]];
    cnt1[nxt1[i]]++;
   }
  }
  for(int i=1;i<=n;i++)
  {if(l[i]==i||l[i]==1) {nxt2[i]=0;continue;}
   if(l[l[i]]==l[l[i]+1])
   {if(l[i]+2<i) if(l[l[i]]==l[l[i]+2]) {nxt2[i]=0;continue;}
    cnt2[l[i]]++;nxt2[i]=l[i];
    //l[i]=l[i]+1;
   }
   else
   {nxt2[i]=nxt2[l[i]];
    cnt2[nxt2[i]]++;
   }
  }
  for(int i=1;i<=n;i++)
  cout<<nxt1[i]<<' '<<nxt2[i]<<'\n';
  */
  long long ans=0;
  for(int i=1;i<n;i++) ans+=1ll*cnt1[i]*cnt2[i];
  cout<<ans<<'\n';
 }
}
