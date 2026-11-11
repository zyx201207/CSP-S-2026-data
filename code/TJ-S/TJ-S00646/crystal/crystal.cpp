#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
int t=1;
const int N=5e5+50;
ll n,m,a[N]; 
//wo_tang_wan_le
//zhi_you_zeng_jia_,_mei_you_jian_shao
//yong_bu_shang_dui_ding_dui 

//multiset<ll>lt;
//multiset<ll>gt;
//ll middle,need;
//void balance()
//{
//	if(lt.size()>gt.size()+1)
//	{
//		gt.insert(*lt.rbegin());
//		auto it=lt.end();it--;
//		lt.erase(it);
//		need-=(lt.size()+1)*(middle-*lt.rbegin());
//		need+=(gt.size()-1)*(middle-*lt.rbegin());
//		middle=*lt.rbegin();
//	}
//	if(lt.size()<gt.size())
//	{
//		lt.insert(*gt.begin());
//		gt.erase(gt.begin());
//		need-=(gt.size()+1)*(*lt.rbegin()-middle);
//		need+=(lt.size()-1)*(*lt.rbegin()-middle);
//		middle=*lt.rbegin();
//	}
//}
//bool check(int cnt)
//{
//	lt.clear();gt.clear();
//	lt.insert(a[1]);
//	middle=a[1];need=0;
//	for(int i=2;i<=cnt;i++)
//	{
//		if(a[i]>middle)
//		{
//			gt.insert(a[i]);need+=a[i]-middle;
//		}
//		else 
//		{
//			lt.insert(a[i]);need+=middle-a[i];
//		}
//		balance();
//	}
//	cerr<<cnt<<' '<<need<<' '<<middle<<'\n'; 
//	if(need<=m)return 1;
//	for(int L=2,R=cnt+1;R<=n;L++,R++)
//	{
//		if(a[L-1]>middle)
//		{
//			gt.erase(gt.find(a[L-1]));need-=a[L-1]-middle;
//		}
//		else 
//		{
//			lt.erase(lt.find(a[L-1]));need-=middle-a[L-1];
//		}
//		balance();
//		if(a[R]>middle)
//		{
//			gt.insert(a[R]);need+=a[R]-middle;
//		}
//		else 
//		{
//			lt.insert(a[R]);need+=middle-a[R];
//		}
//		balance();
//		cerr<<cnt<<' '<<need<<' '<<middle<<'\n'; 
//		if(need<=m)return 1;
//	}
//	return 0;
// } 
bool check(ll mid)
{
	ll need=0;
	for(int i=1;i<=mid;i++)
	{
		need+=a[mid]-a[i];
	}
	if(need<=m)return 1;
	for(int L=2,R=mid+1;R<=n;L++,R++)
	{
		need-=a[R-1]-a[L-1];
		need+=a[R-1]-a[R];
		need+=mid*(a[R]-a[R-1]);
		if(need<=m)return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll L=1,R=n+1,mid;
	while(L<R)
	{
		mid=(L+R)>>1;
		if(check(mid))L=mid+1;
		else R=mid;
	}
	cout<<L-1<<'\n';
	return ;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}

