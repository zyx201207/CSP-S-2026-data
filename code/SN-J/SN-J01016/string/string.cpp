#include<iostream>
#include<vector>
#include<algorithm>
#define pic pair<int,char>
#define int long long
using namespace std;
vector<pic> a,b,que;int n;
int fa[2000005],fb[2000005];
vector<int> changed;

bool check(int i)
{//aabbc
 //cbbaa
 //cout<<"check"<<i<<endl;
	int _idx_of_a=lower_bound(fa,fa+n,i)-fa;
	int _idx_of_b=lower_bound(fb,fb+n,i)-fb;
	
	//cout<<_idx_of_a<<a[_idx_of_a].second<<endl;
	//cout<<_idx_of_b<<b[_idx_of_b].second<<endl;
	
	return a[_idx_of_a].second==b[_idx_of_b].second;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	int _idx=1;
	for(int i=0;i<n;i++)
	{
		int len;char ch;cin>>len>>ch;
		a.push_back({_idx,ch});
		que.push_back({len,ch});
		fa[i]=_idx;
		changed.push_back(_idx);
		_idx+=len;
	 } 
	 
	 
	_idx=1;
	
	for(int i=n-1;i>=0;i--)
	{
		int len=que[i].first;char ch=que[i].second;
		
		b.push_back({_idx,ch});
		fb[n-i-1]=_idx;
		changed.push_back(_idx);
		_idx+=len;
	 } 	
	 
	 
	 sort(changed.begin(),changed.end());
	 
	 
	//for(int i=0;i<n;i++)cout<<fa[i]<<" ";cout<<endl;
	//for(int i=0;i<n;i++)cout<<fb[i]<<" ";cout<<endl;
	 
	
	 
	 
	 int ans=0;
	 for(int i=1;i<changed.size();i++)
	 {
	 	
	 	if(changed[i]>_idx/2)break;
	 	int diff=changed[i+1]-changed[i];
	 	
	 	//cout<<"diff"<<diff<<endl;
	 	if(check(i)==0)ans+=diff;
	 	
	 }
	 
	 cout<<ans;
}
