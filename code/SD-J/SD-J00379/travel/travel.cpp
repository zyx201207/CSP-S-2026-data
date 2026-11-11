#include <bits/stdc++.h>
using namespace std;
struct ren{
	pair<string,char> num;
	string c,s;
	void to_num(){
		num.first="";
		num.first+=s[0],
		num.first+=s[1],
		num.second=s[2];
	}
}R,X;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>R.c>>R.s>>X.c>>X.s;
	R.to_num();
	X.to_num();
	if(R.c==X.c)
	{
		cout<<1;
		if(R.num.first==X.num.first)
		{
			cout<<1;
			if(( (R.num.second<='F'&&R.num.second>='D')&&(X.num.second<='F'&&X.num.second>='D') )||(((R.num.second<='C'&&R.num.second>='A'))&&((X.num.second<='C'&&X.num.second>='A'))))
			{
				cout<<1;
				if(abs(R.num.second-X.num.second)==1)
				cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	
	}	
	else cout<<0<<0<<0<<0;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
