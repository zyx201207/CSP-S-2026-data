#include<iostream>
#include<fstream> 
#include<vector>
using namespace std;
long long Quad[2000007];
int main()
{
	char yh;
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,inner,minif,maxif,result=0,savtemp=0,metrixsources0x65=0,link;
	cin>>n>>m;
	vector<long long>cry;
	for(int i=0;i<n;i++)
	{
		cin>>inner;
		cry.push_back(inner+1000000);
	}
	for(long long i=0;i<n;i++)
	{
		Quad[cry[i]]++;
	}
	for(int i=0;i<=2000000;i++)
	{
		if(Quad[i]!=0){
		minif=i;
		break;
		}
	}
	for(int i=2000000;i>=0;i--)
	{
		if(Quad[i]!=0){
		maxif=i;
		break;
		}
	}
	for(long long goal=minif;goal<maxif;goal++)
	{
		if(Quad[goal]==0)
		continue;
		else
		{
			long long metrix0x19=goal; 
			metrixsources0x65=m;
			savtemp=1;
			while(--metrix0x19)
			{
				if(metrix0x19<minif)
				{
					
					goto sources0x44;
				}
				link=goal-metrix0x19;
				for(int j=0;j<Quad[metrix0x19];j++)
				{
					if(metrixsources0x65>=link)
					{	
						metrixsources0x65=metrixsources0x65-link;
						savtemp++;
					}
					else
					{
						if(savtemp>result)
						result=savtemp;
						goto sources0x44;
					}
				}
			}
		}
		sources0x44:;
		if(savtemp>result)
		result=savtemp;
	}
	cout<<result;
 } 
