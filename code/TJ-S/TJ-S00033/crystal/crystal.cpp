#include<bits/stdc++.h>
using namespace std;
typedef long long ull;
int n,t1,t2,last;
ull m,t,p,cnt,lastt;
map<ull,int> ma;
ull v[500001],v1[500001];
int cr[500001]={0};
int main()
{
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> t;
		ma[t]++;
		p+=t;
	}
	p/=n;t=1;
	for(auto i:ma)
    {
        v[t]=i.first;
        v1[t]=i.first*i.second+v1[t-1];
        cr[t]=i.second+cr[t-1];
        t++;
    }
    n=t-1;t=0;
    last=cr[upper_bound(v,v+n,p)-v-2];
    lastt=t1*p-v1[upper_bound(v,v+n,p)-v-2];
	while(1)
	{
	    t2=upper_bound(v,v+n,p)-v-1;
        t1=cr[t2];
        t=t1*p-v1[t2];
        if(t>m)
        {
            cout << last;
            break;
        }
        p++;
        last=t1;
        lastt=t;
	}
	return 0;
}

