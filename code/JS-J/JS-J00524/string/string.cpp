#include<bits/stdc++.h>
using namespace std;




const int N=200005;
int n,ax[200005],s=0,ss=0;
char c[N],c1[N],c2[N];
int a1[N],a2[N],l1=1,l2=1,i,cnt=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    //int mid=int(n/2.0+0.5);
    for(i=1;i<=n;i++)
    {
        cin>>ax[i]>>c[i];
        ss+=ax[i];
    }
    for(i=1;s<ss/2;i++)
    {
        s+=ax[i];
        s=min(ss/2,s);
        a1[l1]=s;
        c1[l1++]=c[i];
    }
    s=0;
    for(int j=n;s<ss/2;j--)
    {
        s+=ax[j];
        s=min(s,ss/2);
        a2[l2]=s;
        c2[l2++]=c[j];

    }
    l1--;l2--;
   // for(int i=1;i<=max(l1,l2);i++) cout<<a1[i]<<' '<<c1[i]<<" "<<a2[i]<<' '<<c2[i]<<endl;
    int i1=0,i2=0;
   // cout<<l1<<" "<<l2;
    for(;i1<=l1||i2<=l2;){

        if(a1[i1+1]>a2[i2+1]||i1>=l1)//Trick||Treat!
        {
           i2++;
           cnt+=max(a1[i1]-a2[i2-1],0)*(c2[i2]!=c1[i1]);
           //cout<<cnt<<endl;
        }
        if(a1[i1+1]<=a2[i2+1]||i2>=l2)
        {
           i1++;
           cnt+=max(a2[i2]-a1[i1-1],0)*(c1[i1]!=c2[i2]);
           //cout<<cnt<<endl;
        }
    }
    cout<<cnt;
    return 0;
}
