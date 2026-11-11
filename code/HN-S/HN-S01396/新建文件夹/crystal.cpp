#include<bits/stdc++.h>
using namespace std;
int n,ans,num,cnt;
long long m;
struct node{
	long long c,b,sum;
}a[10005];	
//bool cmp(node x,node y)
//{
//	return a.x<=a.y;
//}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		cin>>a[i].c;
	}
	for(int i =1;i<=n;i++){
		a[a[i].c].b+=1;
	}
	int num=0;
	for(int i=1;i<=n;i++)
	{
		num=max(a[i].b,a[i+1].b);
	} 
	ans=num;
	for(int i=1;i<=n;i++){
		if(a[i].c!=a[a[i].b].c)
		{
			if(m-(num-a[i].c)>=0){
				ans++;
				m-=a[i].b;
			}
		} 
	}	
	cout<<ans-1;
	return 0;
}
