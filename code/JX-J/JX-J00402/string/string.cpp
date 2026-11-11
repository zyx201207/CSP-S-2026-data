#include<bits/stdc++.h>
using namespace std;
pair<long long,char> q1,q2;
long long n;
pair<long long,char> a[2000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long w1=1,w2=n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    bool b=1;
    long long sum=0;
    while(b)
    {
        if(q1.first>=q2.first)
        {
            q2.second=a[w2].second;
            if(q2.second!=q1.second)
            {
                sum+=(min(q1.first,q2.first+a[w2].first)-q2.first);
            }
            q2.first+=a[w2--].first;
        }else
        {
            q1.second=a[w1].second;
            if(q2.second!=q1.second)
            {
                sum+=(min(q2.first,q1.first+a[w1].first)-q1.first);
            }
            q1.first+=a[w1++].first;
        }
        //cout<<q1.first<<" "<<q1.second<<" "<<q2.first<<" "<<q2.second<<" "<<sum<<endl;
        if(w1>n&&w2<1)
        {
            b=0;
        }
    }
    cout<<sum/2;
    return 0;
}
//qwweee rttttt
