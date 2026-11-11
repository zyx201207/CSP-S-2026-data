#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int zuoa,zuob;
int hanga,hangb;
int weia,weib;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	zuoa=(a[0]-'0')*10+(a[1]-'0');
	zuob=(c[0]-'0')*10+(c[1]-'0');
	hanga=(b[0]-'0')*10+(b[1]-'0');
	hangb=(d[0]-'0')*10+(d[1]-'0');
	weia=b[2]-'A'+1;weib=d[2]-'A'+1;
	if(weia==6) weia=5;if(weib==6) weib=5;
	if(zuoa!=zuob){
		cout<<"0000\n";return 0;
	}
	cout<<"1";
	if(hanga!=hangb){
		cout<<"000\n";return 0;
	}
	cout<<"1";
	if(weia/4!=weib/4){
		cout<<"00\n";return 0;
	}
	cout<<"1";
	if(abs(weia-weib)>1){
		cout<<"0\n";return 0;
	}
	cout<<"1\n";
	return 0;
}
