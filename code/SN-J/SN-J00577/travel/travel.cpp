#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
int c1, c2;
string s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2)
		cout<<"0000\n";
	else{
		cout<<"1";
		int p1 = (s1[0] - '0') * 10 + (s1[1] - '0'), p2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		if(p1 != p2)
			cout<<"000\n";
		else{
			cout<<"1";
			char st1 = s1[2] - 'A', st2 = s2[2] - 'A';
			int f1, f2;
			if(st1 >= 0 && st1 <= 2)
				f1 = 1;
			else if(st1 == 3 || st1 == 5)
				f1 = 0;
			if(st2 >= 0 && st2 <= 2)
				f2 = 1;
			else if(st2 == 3 || st2 == 5)
				f2 = 0;
			if(f1 != f2)
				cout<<"00\n";
			else{
				cout<<"1";
				bool pd = 0;
				if(f1 == 0 || (st1 == 0 && st2 == 1) || (st1 == 1 && st2 == 0) || (st1 == 1 && st2 == 2) || (st1 == 2 && st2 == 1))
					pd = 1;	
				if(pd)
					cout<<"1\n";
				else
					cout<<"0\n";
			}		
		} 
	}
	return 0;
}
//?!O(1)!?
//CCF = Chinese Can FLY!!! = CPL Can FLY!!!!!!!
