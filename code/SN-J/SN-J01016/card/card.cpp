//假掉了 只能过特殊性质A
 
#include<iostream>
#include<stack>
using namespace std;
int a[500005],instack[500005],ans[500005];
int time_when_add_to_stack[500005];
stack<int> st;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	//for(int i=n-1;i>=0;i--) 
	{
		cin>>a[i];
	}
	
	if(1)
	{ 
	
	for(int i=n;i>0;i--)
	{
		
		if(instack[a[i]]==1)
		{
			while(!st.empty())
			{
				int top=st.top();
				if(top==a[i])break;
				instack[top]=0;
				ans[top]+=time_when_add_to_stack[top]-i;
				st.pop();
			}
		}
		else st.push(a[i]),instack[a[i]]=1,time_when_add_to_stack[a[i]]=i;
		
	}
	
	while(!st.empty())
	{
		int top=st.top();
		ans[top]+=time_when_add_to_stack[top];
		st.pop();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
		}	
			
		
	 }
	 else{
	 	
	 	
	while(n-->1)
	{
	for(int i=n;i>0;i--)
	{
		
		if(instack[a[i]]==1)
		{
			while(!st.empty())
			{
				int top=st.top();
				if(top==a[i])break;
				instack[top]=0;
				st.pop();
			}
		}
		else st.push(a[i]),instack[a[i]]=1;
		
	}
	
	while(!st.empty())
	{
		int top=st.top();
		ans[top]++;instack[top]=0;
		st.pop();
	}	
			
	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
		}
		
	 }	
	 
	 
	 
 } 
