#include<bits/stdc++.h>
using namespace std;
long long n=0,i=0,m=0;//小 R 有 n 颗能量水晶  其中第 i 颗  至多 m 次操作
long long a[10000005];
long long d[10000005];
long long l[10000005];
//  n  m
//  n * a
long long read()
{
        long long s, t = 0;
        long long ch = 0;
        s = getchar();
        while(s < '0' || s > '9')
        {
                if(s == '-')
                {
                        t = -1;
                }
                s = getchar();
        }
        
        while(s >= '0' && s <= '9')
        {
                ch = (ch * 10) + (s - '0');
                s = getchar();
                
        }
        return (ch * t);

}
void tt()
{
        bool w=false;
        do
        {
                for(long long j = 1;j<n;j++)
                {
                        if(a[j]>a[j+1])
                        {
                                long long jh;
                                jh = a[j];
                                a[j] = a[j+1];
                                a[j+1] = jh;
                                w=true;
                        }
                        else
                        {
                                w=false;
                        }
                }
                
        }
        while(w);
        
        
}
int main()
{
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
        cin>>n>>m;
        for(long long iio = 1; iio<=n; iio++)
        {
                cin>>a[iio];
        }
        tt();
        long long mm = m;
        for(long long j=1;j<n && j<10000004;j++)
        {
                if(mm>0)
                {
                        if(mm>(a[j+1]-a[j]))
                        {
                                mm=mm-(a[j+1]-a[j]);
                                a[j]=a[j+1];
                        }
                }
        }
        //cout<<"mm:"<<mm<<endl;
        long long pl=10000005;
        while(pl)
        {
                l[pl] = 0;
                pl--;
        }
        for(long long j=1;j<n;j++)
        {
                l[a[j]]++;
                //cout<<"a[j"<<a[j]<<endl;
        }
        long long yef=0;
        for(long long j=0;j<10000005;j++)
        {
                if(l[j]>yef)
                {
                        
                        yef=l[j];
                        //cout<<"yef:"<<yef<<endl;
                }
        }
        cout<<yef+1;
        fclose(stdin);
        fclose(stdout);
        return 0;
}
