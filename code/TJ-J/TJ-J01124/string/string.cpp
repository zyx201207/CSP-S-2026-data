#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,cnt;
struct Node
{
	long long num;
	char a;
};
Node q[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>q[i].num>>q[i].a;
	}
	long long i=1,j=n;
	while(i<j)
	{
		if(q[i].a!=q[j].a) cnt+=min(q[i].num,q[j].num);
		long long minn=min(q[i].num,q[j].num);
		q[i].num-=minn;
		q[j].num-=minn;
		if(q[i].num==0)i++;
		if(q[j].num==0)j--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
2 a
2 b
1 c


*/
