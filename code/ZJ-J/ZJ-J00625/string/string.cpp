#include<iostream>
#include<vector>
#define Max 200005
namespace my
{
	using std::cin;
	using std::ios;
	using std::cout;
	using std::pair;
	using std::vector;
	using std::istream;
}
using namespace my;
int n;
int m;//拼接完后的字符串数 
unsigned long long len;
unsigned long long ans;
struct my_string
{
	unsigned long long a;
	char c;
}str;
vector<my_string> vec;//记录每一段字符串
vector<pair<unsigned long long,unsigned long long>> xb;//记录每一段字符串起始和终止下标 
istream& operator>>(istream& in,my_string& s)
{
	in>>s.a>>s.c;
	return in;
}
void work(void)
{
	int li=1,ri=m;
	unsigned long long x=1;
	unsigned long long ta,tb;
	while(li<ri)
	{
		ta=xb[li].second-x+1;
		tb=(len-x+1)-xb[ri].first+1;
		if(ta>tb)
		{			
			if(vec[li].c!=vec[ri].c)
				ans+=tb;
			x+=tb;
			--ri;
		}
		else if(ta==tb)
		{			
			if(vec[li].c!=vec[ri].c)
				ans+=ta;
			x+=ta;
			--ri;
			++li;
		}
		else//if(ta<tb)
		{
			if(vec[li].c!=vec[ri].c)
				ans+=ta;
			++li;
			x+=ta;			
		}		
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vec.push_back(my_string{0,'*'});
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>str;
		len+=str.a;
		if(i==1)
		{
			vec.push_back(str);
			m=1;
			continue;
		}
		if(str.c!=vec[m].c)
		{
			vec.push_back(str);
			++m;
		}			
		else//把内容相同的字符串拼在一起 
			vec[m].a+=str.a;
	}
	xb.push_back({0,0});
	for(int i=1;i<=m;++i)
	{
		xb.push_back({xb[i-1].second+1,xb[i-1].second+vec[i].a});
	}
	work();
	cout<<ans;
	return 0;
}
