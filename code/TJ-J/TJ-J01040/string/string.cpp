#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans,ml=0;
char c[200005] ;
vector< pair<long long,char> > l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n ;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i] ;
		ml+=a[i];
	}
	long long len=0,k=0;
	while(len<ml/2)
	{
		k++;
		if(len+a[k]>ml/2)
		{
			//cout << len << ' ' << ml << ' ' << a[k] ;
			l.push_back(make_pair(ml/2-len,c[k]));
			a[k]-=(ml/2-len);
			if(ml%2==1) a[k]-=1;
			break;
		}
		else
		{
			l.push_back(make_pair(a[k],c[k]));
			len+=a[k];
		}
		a[k]=0;
	}
	k=n;
	while(a[k]!=0)
	{
		if(a[k]<0) cout << a[k]  << endl ;
		r.push_back(make_pair(a[k],c[k]));
		k--;
	}
	
	//long long ll=0,rl=0;
	//for(int i=0;i<l.size();i++) ll+=l[i].first;
	//cout << '!' << endl ;
	//for(int j=0;j<r.size();j++) rl+=r[j].first;
	//cout << ll << ' ' << rl ;
	long long L=0,R=0,i=-1,j=-1;
	while(1)
	{
		//cout << 3 << endl ;
		//cout << i << ' ' << j << endl ;
		//cout << i << ' ' << j << endl ;
		if(i==l.size()||j==r.size()) break;
		if(L<=R)
		{
			i++;
			if(j!=-1)
			{
				if(l[i].second != r[j].second)
				{
					if(L+l[i].first <= R)
					{
						ans+=l[i].first;
					}
					else
					{
						ans+=R-L;
					}
				}
			}
			L+=l[i].first;
		}
		else
		{
			j++;
			if(r[j].second != l[i].second )
			{
				if(L >= R+r[j].first)
				{
					ans+=r[j].first;
				}
				else
				{
					ans+=L-R;
				}
			}
			R+=r[j].first;
		}
	}
	cout << ans ;
	return 0;
}
