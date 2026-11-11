#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;


int n;
int ans;
deque<pair<int,int>> a;
string s;

void xiaochu()
{
	while(!a.empty())
	{
		if(a.size()==1) break;
		int c1=a.front().second,c2=a.back().second;
		int cnt1=a.front().first,cnt2=a.back().first;
		if(c1!=c2) break;
		if(cnt1==cnt2)
		{
			a.pop_front();
			a.pop_back();
		}
		else if(cnt1<cnt2)
		{
			a.pop_front();
			a.back().first=cnt2-cnt1;
		}
		else
		{
			a.pop_back();
			a.front().first=cnt1-cnt2;
		}
	}
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int cnt;
		char c;
		cin>>cnt>>c;
		int y=c-'a'+1;
		if(!a.empty())
		{
			
			if(a.back().second==y)
			{
				cnt+=a.back().first;
				a.pop_back();
			}
		}
		a.push_back({cnt,y}); 
	}
//	for(auto it:a) cout<<it.first<<" "<<it.second<<"\n";
	xiaochu();
	if(a.size()==1)
	{
		cout<<0;
		return 0;
	}
	
	while(!a.empty())
	{
		if(a.size()==1) break;
		int c1=a.front().second,c2=a.back().second;
		int cnt1=a.front().first,cnt2=a.back().first;
		if(cnt1==cnt2)
		{
			ans+=cnt2;
			a.pop_front();
			a.pop_back();
		}
		else if(cnt1<cnt2)
		{
			ans+=cnt1;
			a.pop_front();
			a.back().first=cnt2-cnt1;
		}
		else
		{
			ans+=cnt2;
			a.pop_back();
			a.front().first=cnt1-cnt2;
		}
		xiaochu();
	}
	cout<<ans;
	return 0;
}
//6
//2 a
//2 b
//1 c
//1 f
//1 e
//3 b

//4
//2 a
//2 b
//1 c
//3 a

//6
//1000000000 b
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 a

//2
//2 a
//3 a

//6
//2 f
//2 f
//1 f
//1 f
//1 f
//3 f