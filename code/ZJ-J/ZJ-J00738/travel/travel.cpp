#include<bits/stdc++.h>
using namespace std;
int Change(string s)
{
	int y=0;
	for(int i=0;i<s.size();i++) y=(y<<3)+(y<<1)+int(s[i]-'0');
	return y;
}
bool same_t(string a,string b)
{
	if(a>b) swap(a,b);//a<b
	if(a=="A"&&b=="B") return true;
	if(a=="C"&&b=="D") return true;
	if(a=="D"&&b=="E") return true;
	if(a=="C"&&b=="E") return true;
	return false;
}
bool Next(string a,string b)
{
	if(a=="A"&&b=="B") return true;
	if(a=="C"&&b=="D") return true;
	if(a=="D"&&b=="E") return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string Car_x,Car_r;
	string Seat_x,Seat_r;
	cin>>Car_x>>Seat_x>>Car_r>>Seat_r;
	bool Same_Car=(Car_x==Car_r);//在同一车厢 
	
	string number_x=Seat_x.substr(0,2);
	string number_r=Seat_r.substr(0,2);
	int Number_x=Change(number_x);
	int Number_r=Change(number_r);
	bool Same_cross=(Number_x==Number_r);//在同一排 
	
	string Number_Seat_x=Seat_x.substr(2);
	string Number_Seat_r=Seat_r.substr(2);
	bool Same_t=same_t(Number_Seat_x,Number_Seat_r);//在同一侧 
	
	bool Next_to=Next(Number_Seat_x,Number_Seat_r);//相邻 
	
	bool ans[4];
	ans[0]=(Same_Car);
	ans[1]=(Same_cross&ans[0]);
	ans[2]=(Same_t&ans[1]);
	ans[3]=(Next_to&ans[2]);
	for(int i=0;i<4;i++) cout<<ans[i];
	return 0;
}
