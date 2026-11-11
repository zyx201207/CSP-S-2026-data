#include<bits/stdc++.h> 
using namespace std;
int c,cc,tj[10]={0};
string s,ss;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c!=cc)
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	else
	{
		cout<<1;
		if((s[0]-'0')*10+(s[1]-'0')!=(ss[0]-'0')*10+(ss[1]-'0'))
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
		else
		{
			cout<<1;
			tj[s[2]-'A'+1]++;
			tj[ss[2]-'A'+1]++;
			if((tj[4]+tj[5]!=2)&&(tj[1]+tj[2]+tj[3]!=2))
			{
				cout<<0;
				cout<<0;
			}
			else
			{
				cout<<1;
				if((tj[4]+tj[5]==2)||(tj[1]+tj[2]==2)||(tj[2]+tj[3]==2))cout<<1;
				else cout<<0;
			} 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
