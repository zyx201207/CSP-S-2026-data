#include<bits/stdc++.h>
using namespace std;
int b[1000];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    for(long long k=0;k<t;k++)
    {
       // cout<<c<<"!"<<t;
        int  n,d;
        cin>>n>>d;
        int x[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
            cout<<x[i];
        }
        cout<<1;
 //       int flag=1;
   //     for(int i=0;i<n;i++)
     //   {

       //     for(int j=i;j<n;j++)
         //   {
            int ans=0;
            //cout<<"!";
            for(int i=0;i<n;i++)
            {
                for(int j=i;j<n;j++)
                {
                        if(i==j) continue;
                            int mi=1000;
                            int ans=0;
                    for(int s=0;s<pow(2,j-i);s++)
                    {

                        int num=s;
                        int cnt1=0,cnt2=0;
                        int a[j-i];
                        while(num>0)
                        {
                            a[cnt1]=num%2;
                            num%=2;
                            cnt1+=1;

                        }
                        if(cnt1<i-j) for(int t=cnt1+1;t<i-j;t++) a[t]=0;
                        int now=x[i];
                        for(int t=0;t<i-j;t++)
                        {
                            if(a[i]==1 and x[i+t]-now>d) break;
                            if(a[i]==1 and x[i+t]-now<d) {now=x[i+t]; cnt2++;}
                        }
                        if(cnt2!=0){
                            b[cnt2]++;
                            mi=min(cnt2,mi);
                        }
                    }
                    if(b[mi]>=2) ans++;

                }

            }
            cout<<ans;
        }


    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

