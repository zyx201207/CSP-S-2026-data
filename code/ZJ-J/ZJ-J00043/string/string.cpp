#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long num;
	char ch;
}pos[200009];
int main()
{	 
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&pos[i].num,&pos[i].ch);
	}
	int left=1,right=n;
	while(left < right)
	{
		if(pos[left].num< pos[right].num)
		{
			if(pos[left].ch != pos[right].ch)
				ans += pos[left].num;
			pos[right].num-= pos[left].num;
			left++;	
		}
		else if(pos[left].num > pos[right].num)
		{
			if(pos[left].ch != pos[right].ch)
				ans += pos[right].num;
			pos[left].num-= pos[right].num;
			right--;	
		}	
		else 
		{
			if(pos[left].ch != pos[right].ch)
				ans += pos[right].num;
			left++;
			right--;
		}
	}
	printf("%lld",ans);
	return 0;
}
