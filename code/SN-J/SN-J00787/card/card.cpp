#include<bits/stdc++.h>//张哲 庆安初级中学 SN-J00787
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],sum[M];
string temp;
int main()
{
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		temp="";
		for(int j=i;j<=n;j++)
		{
			bool f=0;
			string s="";
			for(int k=i;k<=n;k++)
			{
				if(temp[k]==a[j])
				{
					f=1;
					for(int l=0;l<k;l++) s+=temp[k]; 
				}
			}
			s+=a[j];
			if(f==0) temp+=a[j];
			else temp=s;
		}
		for(int j=0;j<temp.size();j++) sum[temp[j]-'0']++;
		
	}
	for(int i=0;i<m;i++) cout<<sum[i]<<' ';
	return 0;
}
