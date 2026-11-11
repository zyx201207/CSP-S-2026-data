#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,hp,hpp;
struct node{
	long long dt,si;
	vector <long long> v;
};
node s[700005];
long long a[700005];
bool cmp(long long a,long long b)
{
	return a<b;
}
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n>>m;
	long long i,j,pre;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<n;i++)
	{
		s[i].dt=a[i+1]-a[i];
		if(s[i].dt==0)
		{
			if(i!=1){
				s[i].v.push_back(0);
				j=0;
				while(true)
				{
					if(s[i-1].v.empty())
						break;
					if((s[i-1].v.size()-1)<j)
					{
						break;
					}
					hp=s[i-1].v[j];
					if(hp>m)
					{
						break;
					}
					s[i].v.push_back(hp);
					j++;
				}
				hpp=s[i].v.size();
				ans=max(ans,hpp);
			}
			else{
				s[i].si=1;
				s[i].v.push_back(0);
				ans=1;
			}
		}
		else
		{
			pre=i-1;
			s[i].v.push_back(s[i].dt);
			j=0;
			while(true)
			{
				if(s[pre].v.empty())
					break;
				if((s[pre].v.size()-1)<j)
				{
					break;
				}
				hp=s[i].v.back()+s[pre].v[j]+s[i].dt;
				if(hp>m)
				{
					break;
				}
				s[i].v.push_back(hp);
				j++;
			}
			if(s[i].v.empty()){
				continue;
			}
			hpp=s[i].v.size();
			ans=max(ans,hpp);
		}
	}
	if(ans!=0)
	{
		ans+=1;
	}
	cout<<ans;
	return 0;
	//¼ÇµÃ¸Ä×¢ÊÍ 
}
