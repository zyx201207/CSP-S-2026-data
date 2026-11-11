/*
嗨你好，很高兴能被你看见
今年是我最后一次参加信息奥赛了，自从去年考砸之后，我已经是半退役的人了 
不说那些不好的了，一切都会好起来的，哪怕不在自己喜欢的领域，也要全力以赴 

不以谋生为目标，而以生活为使命——索洛 
如果不通过黑暗之径，人们不能抵达黎明——黑塞 
世界上只有一种英雄主义，那就是在认清生活真相后依然热爱生活——罗曼罗兰 
守正不移，致远不泥——钱钟书 
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+9;
ll  A[N],S[N];ll m;
int n,ans;

/*
5 5
1 2 4 8 9

3
*/
/*
5 8
-3 -1 2 2 7

4
*/

inline ll  read();

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf ("%d",&n),m=read();
	for (int i=1;i<=n;i++)
		A[i]=read();
	stable_sort(A+1,A+n+1);
	for (int i=1;i<=n;i++)
		S[i]=S[i-1]+A[i];
	
	ans=1;
	int dl=1;
	for (int i=2;i<=n;i++)
	{
		while (A[i]*(i-dl+1)-(S[i]-S[dl-1])>m and dl<i)
			dl++;
		if (dl<i)
			ans=max(ans,i-dl+1);
	}
	
	printf ("%d\n",ans);
	
	return 0;
}

inline ll read()
{
	ll o=0,c=0,g=0;
	while (c<'0' or c>'9')
		g=(c=='-'),c=getchar();
	while (c>='0' and c<='9')
		o=(o<<1)+(o<<3)+(c^48),c=getchar();
	return (!g)?o:-o;
}


