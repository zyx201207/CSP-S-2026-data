#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],b[300005],vis[500010];

void kang(int x,int &sum)//出的牌a[x]，sum b数组长度 
{
	//sum==0时候，不用找。 
	if(sum==0){
		sum++;
		b[sum]=a[x];
		return;
	}
	//查找b数组有没有出的牌a[x] 
	int len=0;//标记b数组中第一次查找到a[x]的位置 
	bool flag=true;//是否查到 
	for(int i=1;i<=sum;i++)
	{
		if(b[i]==a[x]){//查到 
			flag=false;
			len=i;//标记 
			break;
		}
	}
	//查到 
	if(flag==false)
	{
		int p=0;//拿走了多少张牌 
		for(int i=len;i<=sum;i++){
			b[i]=0;//收牌 
			p++;
		}
		sum-=p;//现有牌数 
		sum++;//a[x]摆放位置 
		b[sum]=a[x];//放数 
	}
	//没找到 
	else{
		sum++;
		b[sum]=a[x];
	}
} 

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	int num=0;
	for(int i=1;i<=n;i++)
	{
		
		memset(b,0,sizeof(b));
		num=0;
		 
		for(int j=i;j<=n;j++)
		{
			kang(j,num); 
		}
		for(int j=1;j<=num;j++)
		{
			vis[b[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<vis[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
