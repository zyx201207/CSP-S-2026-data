#include<bits/stdc++.h>
using namespace std;
struct zhan{
	int paidui[500010]={0};
	int _kind;
	int _top=0;
};
zhan a;
int s[500010]={0};
int ff[500010]={0};
int my_ans[300010]={0};
int n;

void my_add(int);
void my_delete(int);
void my_clear();
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>a._kind;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			my_add(s[j]);
		}
		while(a._top)
		{
			//cout<<a.paidui[a._top]<<"*";
			my_ans[a.paidui[a._top]]++;
			a._top--;
		}
		//cout<<endl<<endl;
		my_clear();
	}
	for(int i=1;i<=a._kind;i++)
	{
		cout<<my_ans[i]<<" ";
	}
	
	
	return 0;
}
void my_add(int mm)
{
	a._top++;
	a.paidui[a._top]=mm;
	
	/*for(int k=1;k<=a._top;k++)
	{
		cout<<a.paidui[k]<<"*";
	}
	cout<<endl;*/
			
	if(ff[mm]==0)ff[mm]=a._top;
	else{
		//cout<<"delete:"<<mm<<endl;
		my_delete(mm);
	}
}
void my_delete(int num)
{
	for(int i=ff[num]+1;i<a._top;i++)
	{
		ff[a.paidui[i]]=0;
	}
	a._top=ff[num];
	
	/*for(int k=1;k<=a._top;k++)
	{
		cout<<a.paidui[k]<<"*";
	}
	cout<<endl;*/
}
void my_clear()
{
	for(int i=1;i<=a._kind;i++)
	{
		a.paidui[i]=0;
	}
	for(int i=1;i<=a._kind;i++)
	{
		ff[i]=0;
	}
	a._top=0;
}