#include<bits/stdc++.h> 
using namespace std;

int N[500000];
int P[500000];
int main()
{
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>N[i];
	sort(N,N+n);
	P[0]=1;
	for(int i=n-1;i>=1;i--) N[i]=N[i]-N[i-1];
	N[0]=0;
	long long num=0;
	for(int i=1;i<n-1;i++)
	{
		
		if(N[i]!=N[i+1]) break;
		if(i==n-2)
		{
			int ans=1;
			int tmp=m;
			while(tmp-(num+N[1])
			>=0) 
			{
				num+=N[1];
				tmp=tmp-num;
				ans++;
			}
			cout<<ans;
			return 0;
		}	
	} 
	num=0;
	//for(int i=0;i<n;i++) cout<<N[i]<<" ";
	for(int i=1;i<n;i++) 
	{
		//cout<<i<<endl;
		long long tmp=m;
		P[i]=1;
		num=0;
		for(int j=i;j>0;j--) 
		{
			num+=N[j];
			if(num<=tmp) tmp=tmp-num;
			else break;
			P[i]++; 
			//cout<<"i:"<<i<<" "<<tmp<<" "<<N[j]<<" ";
		}
		//cout<<endl;
	}
	//for(int i=0;i<n;i++) cout<<N[i]<<" ";
	//cout<<endl;
	int ans=0;
	//for(int i=0;i<n;i++) cout<<P[i]<<" ";
	for(int i=0;i<n;i++) 
	{
		ans=max(ans,P[i]);
	} 
	cout<<ans;
	return 0; 
}
