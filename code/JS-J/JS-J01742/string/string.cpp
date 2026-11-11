#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll curr_a[200010];
char curr_ch[200010];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll sum=0,n=0;
    string s="";
    cin>>n;
    ll mxcai=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>curr_a[i]>>curr_ch[i];
        mxcai=max(mxcai,curr_a[i]);
        if(curr_a[i]<=10000000)
        {
            for(ll j=1;j<=curr_a[i];j++)
            {
                s+=curr_ch[i];
            }
        }
        sum+=curr_a[i];
    }
    ll pres_ans=0;
    ll i=0,j=sum-1;
    if(mxcai<=10000000)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                pres_ans++;
            }
            i++;j--;
        }
    }
    else
    {
        ll carry=0,sumtilnow=0,kk=sum/2,currf=0;
        ll j=n,i;
        for(i=1;i<=n;i++)
        {
            if(sumtilnow>=kk)
            {
                break;
            }
            currf=curr_a[i];
            sumtilnow+=currf;
            while(j>i&&currf>0)
            {
                ll currb;
                if(carry>0)
                {
                    currb=carry;
                }
                else
                {
                    currb=curr_a[j];
                }
                if(currb>currf)
                {
                    if(curr_ch[j]!=curr_ch[i])
                    {
                        pres_ans+=currf;
                        carry=currb-currf;
                        break;
                    }
                    else
                    {
                        carry=currb-currf;
                    }
                }
                else
                {
                    if(curr_ch[i]!=curr_ch[j])
                    {
                        pres_ans+=currb;
                    }
                    currf-=currb;
                    carry=0;
                    j--;
                }
            }

        }
    }
    cout<<pres_ans<<endl;
    return 0;
}
