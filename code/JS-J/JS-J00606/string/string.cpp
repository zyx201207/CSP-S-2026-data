#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],tot=0,cnt=0;
string s;
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        tot+=a[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=b[i];
        }
        a[i]+=a[i-1];
        //tot+=a[i];
    } 
    tot-=1;
    for(int i=0;i<=tot/2;i++)
    {
        if(s[i]!=s[tot-i]) cnt++;
    }
    cout<<cnt;
    /*int tot_=tot;
    tot/=2;
    int ks=1,rear=1,fini=a[1],rear_=a[n],fini_=a[n-1];
    while(tot>0)
    {
        int rear2=tot_+1-rear,fini2=tot_+1-fini;
        char z1=b[ks],z2=b[fini],y1=b[rear2],y2=b[fini2];
        if(z1==y1)
    }*/
    //cout<<n<<endl;
    return 0;
}