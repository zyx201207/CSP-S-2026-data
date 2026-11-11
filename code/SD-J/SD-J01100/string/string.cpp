#include<bits/stdc++.h>
using namespace std ;
struct jgt
{
	int sl ;
	char zm ;
};
jgt a[200010];
jgt b[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n ; 
	cin>>n; 
	//输入+存入2个结构体数组
	for(int i = 1 ; i <= n ; i++) 
	{
		cin>>a[i].sl;
		cin>>a[i].zm;
		b[n-i+1].sl=a[i].sl;
		b[n-i+1].zm=a[i].zm;
	}
	//计数跑
	long long cnt = 0 ;
	int ai = 1 ; //a的下标
	int bi = 1 ;//b的下标
	while(ai<=n&&bi<=n)
	{
		char ta = a[ai].zm;//a跑到的
		char tb = b[bi].zm;//b的
		int t = min(a[ai].sl,b[bi].sl);
		a[ai].sl-=t;
		b[bi].sl-=t;
		if(ta!=tb)
		cnt+=t;
		if(a[ai].sl==0)
		ai++;//更替 
		if(b[bi].sl==0)
		bi++;
		//cout<<ai<<endl;
	} 
	cout<<cnt/2;
	return 0 ;
}
