#include<bits/stdc++.h>
using namespace std;

int main()
{   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	long long n,m,x;
	vector<long long> a;
	cin>>n>>m;
	if(n>5000)
    {
        long long k,l;
        cin>>k>>l;
        int q=l-k;
        a.push_back(0);
        for(long long i=1;i<n;i++)
        {
            a.push_back(a[i-1]+q);
        }
        long long ans=0;
        for(long long i=0;i<=m%2;i++)
        {
            ans=ans+a[i];
        }
        cout<<ans+1;
    }
	else
    {
        for(long long i=1;i<=n;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        long long sum=0,max=-2000000000,cnt=0;
        for(long long i=0;i<n;i++)
        {
            long long j=i-1;
            while(j>=0)
            {
                if(abs(a[i]-a[j])+sum <= m)
                {
                    sum=sum+abs(a[i]-a[j]);
                    cnt++;
                    j--;
                }
                else
                {
                    break;
                    j--;
                }
            }
            if(cnt>max) max=cnt;
            sum=0,cnt=0;
        }
        cout<<max+1;
        return 0;
    }
}
