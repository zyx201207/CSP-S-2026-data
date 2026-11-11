#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	set<char>l,r;
	l.insert('A');l.insert('B');l.insert('C');r.insert('D');r.insert('F');
	map<char,char>mp;
	mp['A']='B';mp['B']='A';mp['C']='B';mp['D']='F';mp['F']='D';
	if(c1==c2)//两张车票对应的座位是否在同一节车厢
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])//两张车票对应的座位是否在同一节车厢的同一排
		{
			cout<<1;
			if(l.count(s1[2])&&l.count(s2[2])||r.count(s1[2])&&r.count(s2[2]))
			//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
			{
				cout<<1;
				if(mp[s1[2]]==s2[2]||s1[2]=='B'&&s2[2]=='C')//两张车票对应的座位是否相邻
				{
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
