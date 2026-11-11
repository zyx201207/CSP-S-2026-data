#include <bits/stdc++.h>
std::ifstream cin("and1.in");
std::ofstream cout("and1.out");
int two(int a){
	int x,b;
	for(int i=a;i>0;i--){
		b=x%2+10*b;
		x/=2;
	}
	return b;
}
int and__(int a,int b)
{
	int x=a,y=b,and_;
	for(int i=len(max(a,b));i>0;i--)
	{
		if(x[i]==1&&y[i]==1)
		{
			and_[i]=1;
		}
		else{
			and_[i]=0;
		}
	}
	return and_;
}
bool max(int n,int m,int maths[]){
	bool sum;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum=and__(sum,maths(i+j));
		}
		if(sum>max)
		{
			max=sum;
		}
		return max;
	}
}
int main(){
	int n,max=0;
	cin>>n>>m;
	std::string a[n+3];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<and_max(n,m,a[]);
	return 0;
}
