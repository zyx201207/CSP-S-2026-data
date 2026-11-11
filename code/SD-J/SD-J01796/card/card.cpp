#include<bits/stdc++.h>
using namespace std;
int ton[500001],sm[500001];
string s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int a=0;a<n;a++) cin>>sm[a];
	for(int a=0;a<n;a++)
	{
		s="";
		for(int b=a;b<n;b++) 
		{
			if(s.find(sm[b])==-1) s=s+(char)sm[b];
			else
			{
				int len=s.size(); 
				s.erase(s.find(sm[b]),len-(s.find(sm[b])));
			}
		 } 
		 for(int c=0;c<s.size();c++) ton[s[c]]++;
	}
	for(int a=1;a<=m;a++) cout<<ton[a]<<" ";
	return 0;
}


