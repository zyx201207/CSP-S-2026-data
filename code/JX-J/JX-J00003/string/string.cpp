#include<bits/stdc++.h>
using namespace std;
long long lo[300001],sum;
long long le[300001],ri[300001];
long long ty[300001],lt[300001],rt[300001],n;
long long lb,rb,fs,ans;
long long lsu,rsu;
bool bj=false;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char in;
        cin>>lo[i]>>in;
        ty[i]=in-'a'+1;
        sum+=lo[i];
    }
    for(int i=1;i<=n;i++)
    {
        long long kp=fs+lo[i];
        if(kp>sum/2+(sum%2)&&!bj)
        {
          bj=true;
          le[++lb]=sum/2-fs;
          lt[lb]=ty[i];
          lo[i]-=(sum/2-fs+(sum%2));
          ri[++rb]=lo[i];
          rt[rb]=ty[i];
          fs=kp;
          rsu+=ri[rb];
          lsu+=le[lb];
          continue;
        }
        if(bj)
        {
            ri[++rb]=lo[i];
            rt[rb]=ty[i];
            rsu+=ri[rb];
        }
        else
        {
            le[++lb]=lo[i];
            lt[lb]=ty[i];
          lsu+=le[lb];
        }
        if(kp>=sum/2+(sum%2))
            bj=true;
        if(kp==sum/2+1&&sum%2==1){
            le[lb]--;
            lsu--;
        }
        fs=kp;
  }
  long long lh=1;
    while(true)
    {
        if(lt[lh]!=rt[rb])
            ans+=min(le[lh],ri[rb]);
        rsu-=min(le[lh],ri[rb]);
        lsu-=min(le[lh],ri[rb]);
        if(le[lh]>ri[rb]){
            le[lh]-=ri[rb--];
        }
        else
            if(le[lh]<ri[rb])
                ri[rb]-=le[lh++];
                else
                    rb--,lh++;
        if(rsu==0&&lsu==0)
            break;
    }
    cout<<ans;
   fclose(stdin);
   fclose(stdout);
   return 0;
}
