//I don't know if the judger will CE my code because "c1""s1"
//so I reset their names
//small heart drive 10000 years boat 
//rp++
//freopen bits\stdc++.h
//AC at 9:00
//please give me at least 2= orz orz orz

//11:05: I got 100+16+50=166

#include<bits/stdc++.h>
using namespace std;
string firstc,firsts,secondc,seconds;
void last_step()
{
	if(firsts[0]==seconds[0]&&firsts[1]==seconds[1])
	{
		//都在同排（以下均为判断相邻） 
		if((firsts[2]=='F'&&seconds[2]=='d') || (firsts[2]=='d'&&seconds[2]=='F'))
		{
			//都在上侧
			cout<<"1"; 
		}
		else if((firsts[2]=='c'&&seconds[2]=='B') || (firsts[2]=='B'&&seconds[2]=='c'))
		{
			//都在下侧上 
			cout<<"1";
		}
		else if((firsts[2]=='B'&&seconds[2]=='A') || (firsts[2]=='A'&&seconds[2]=='B'))
		{
			//都在下侧下
			cout<<"1"; 
		}
		else
		{
			cout<<"0";
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>firstc>>firsts>>secondc>>seconds;
	if(firstc==secondc)
	{
		//是否同车厢 
		cout<<"1";
		if(firsts[0]==seconds[0]&&firsts[1]==seconds[1])
		{
			//是否同排
			cout<<"1";
			if((firsts[2]=='F'&&seconds[2]=='D') || (firsts[2]=='D'&&seconds[2]=='F'))
			{
				//都在上侧
				cout<<"11";
				return 0; 
			}
			else if((firsts[2]=='C'||firsts[2]=='B'||firsts[2]=='A')&&(seconds[2]!='F'&&seconds[2]!='D'))
			{
				cout<<"1";
				last_step();
			}
			else if((seconds[2]=='C'||seconds[2]=='B'||seconds[2]=='A')&&(firsts[2]!='F'&&firsts[2]!='D'))
			{
				cout<<"1";
				last_step();
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
