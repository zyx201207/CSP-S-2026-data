#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int shu[200005];
    char zimu[200005];
    long long sum=0;
    long long tongji[27];
    for(int i=1;i<=n;i++)
    {
        cin>>shu[i]>>zimu[i];
        sum+=shu[i];
    }
    long long maxn=0,maxnh=0;
    char maxnqzm,maxnhzm;
        for(int i=1;i<=n;i++)
        {
            if(zimu[i]-'a'==0)
            {
                tongji[1]+=shu[i];
            }
            if(zimu[i]-'a'==1)
            {
                tongji[2]+=shu[i];
            }
            if(zimu[i]-'a'==2)
            {
                tongji[3]+=shu[i];
            }
            if(zimu[i]-'a'==3)
            {
                tongji[4]+=shu[i];
            }
            if(zimu[i]-'a'==4)
            {
                tongji[5]+=shu[i];
            }
            if(zimu[i]-'a'==5)
            {
                tongji[6]+=shu[i];
            }
            if(zimu[i]-'a'==6)
            {
                tongji[7]+=shu[i];
            }
            if(zimu[i]-'a'==7)
            {
                tongji[8]+=shu[i];
            }
            if(zimu[i]-'a'==8)
            {
                tongji[9]+=shu[i];
            }
            if(zimu[i]-'a'==9)
            {
                tongji[10]+=shu[i];
            }
            if(zimu[i]-'a'==10)
            {
                tongji[11]+=shu[i];
            }
            if(zimu[i]-'a'==11)
            {
                tongji[12]+=shu[i];
            }
            if(zimu[i]-'a'==12)
            {
                tongji[13]+=shu[i];
            }
            if(zimu[i]-'a'==13)
            {
                tongji[14]+=shu[i];
            }
            if(zimu[i]-'a'==14)
            {
                tongji[15]+=shu[i];
            }
            if(zimu[i]-'a'==15)
            {
                tongji[16]+=shu[i];
            }
            if(zimu[i]-'a'==16)
            {
                tongji[17]+=shu[i];
            }
            if(zimu[i]-'a'==17)
            {
                tongji[18]+=shu[i];
            }
            if(zimu[i]-'a'==18)
            {
                tongji[19]+=shu[i];
            }
            if(zimu[i]-'a'==19)
            {
                tongji[20]+=shu[i];
            }
            if(zimu[i]-'a'==20)
            {
                tongji[21]+=shu[i];
            }
            if(zimu[i]-'a'==21)
            {
                tongji[22]+=shu[i];
            }
            if(zimu[i]-'a'==22)
            {
                tongji[23]+=shu[i];
            }
            if(zimu[i]-'a'==23)
            {
                tongji[24]+=shu[i];
            }
            if(zimu[i]-'a'==24)
            {
                tongji[25]+=shu[i];
            }
            if(zimu[i]-'a'==25)
            {
                tongji[26]+=shu[i];
            }

        }
    if(sum%2==0)
    {
        for(int i=1;i<=26;i++)
        {
            maxn=max(maxn,tongji[i]);
        }
        cout<<sum-maxn;
    }
    else
    {
        for(int i=1;i<=26;i++)
        {
            maxn=max(maxn,tongji[i]);
        }
        if((sum-maxn-1)>0)
        {
            cout<<sum-maxn+-1;
        }
        else if((sum-maxn-1)==0)
        {
            cout<<sum-maxn;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
