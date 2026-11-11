#include<bits/stdc++.h>
using namespace std;
int main()
{
	string ans;
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int acar,bcar;
	string aset,bset;
	cin>>acar>>aset>>bcar>>bset;
	int anumber=10*aset[0]+aset[1];
	int bnumber=10*bset[0]+bset[1];
	char achar=aset[2];
	char bchar=bset[2];
	if(acar==bcar)
	{
	   ans.push_back(1+'0');
	   if(anumber==bnumber)
	   {
	   	  ans.push_back(1+'0');
	   	  if(achar=='A'||achar=='B'||achar=='C'&&bchar=='A'||bchar=='B'||bchar=='C') 
		{
			ans.push_back(1+'0');
			if(achar=='A'&&bchar=='B'||achar=='B'&&bchar=='A'||bchar=='B'||achar=='C'&&bchar=='B')
			{
			  ans.push_back(1+'0');	
			}
			else
			{
				ans.push_back(0+'0');
			}
		}
		else if(achar=='D'&&bchar=='F'||achar=='F'&&bchar=='D')
	   	  {
	   	  	ans.push_back(1+'0');
		    ans.push_back(1+'0');
		} 
		else
		{
            ans.push_back(0+'0');
			ans.push_back(0+'0');		
		}
	   }
	   else
	   {
	   	ans.push_back(0+'0');
	   	ans.push_back(0+'0');
	   	ans.push_back(0+'0');
	   }
	}
	else
	{
	   ans.push_back(0+'0');
	   ans.push_back(0+'0');
	   ans.push_back(0+'0');
	   ans.push_back(0+'0');
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
