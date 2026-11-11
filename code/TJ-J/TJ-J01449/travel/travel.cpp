#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
string c1, s1, c2, s2, a1 = "", a2 = "";
string ans = "0000";
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin>>c1>>s1>>c2>>s2;
	char b1 = s1[2], b2 = s2[2];
	if (c1==c2)
	{
		ans[0] = '1';
		if (s1[0]==s2[0]&&s1[1]==s2[1])
		{
			ans[1] = '1';
			if (('A'<=b1&&b1<='C'&&'A'<=b2&&b2<='C')||('D'<=b1&&b1<='F'&&'D'<=b2&&b2<='F'))
			{
				ans[2] = '1';
				if (b1>b2) 
				{
					swap(b1, b2);
				}
				if (b1+1==b2)
				{
					if (b1=='C'&&b2=='D') ans[3] = '0';
					else ans[3] = '1';
				}
			} 
		}
	} 
	cout<<ans<<'\n';
	
	//气死我了，开场忘了文件输入输出，捣鼓了半小时
	//。
	//好锋芒啊 
	
	return 0;
}
