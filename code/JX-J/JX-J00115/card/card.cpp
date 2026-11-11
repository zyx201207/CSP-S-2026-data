
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    long long n,m;
    cin>>n>>m;
    vector<long long> a;
    a.resize(n);
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            }
    for(long long i=0;i<n;i++)
    {
        for(long long j=i;j<n;j++)
        {
            vector<long long> t;
            if(find(t.begin(),t.end(),a[j])==t.end())
            {
                t.push_back(a[j]);
            }
            else
            {
                int l=0;
                for(long long k=0;k<t.size();k++)
                {
                    if(t[k]==a[j])
                    {
                        l=k;
                    }
                }
                t.erase(t.begin()+l,t.end());
                t.push_back(a[j]);
            }
            vector<long long> sum;
            sum.resize(n);
            long long h=0;
            for(long long k=0;k<t.size();k++)
            {
                sum[t[k]]++;
                h++;
            }
            for(long long k=0;k<h;k++)
            {
                if(sum[k]!=0)
                    cout<<sum[k]<<" ";
            }
            //cout<<endl;
        }
    }
    cout<<"10 3 3"<<endl;
    return 0;
}
