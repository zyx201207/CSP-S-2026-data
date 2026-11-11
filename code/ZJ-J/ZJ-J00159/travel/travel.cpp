#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int r=0, x=0;
int side_r=0, side_x=0, nex=0, row=0, side=0;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	r=s1[0]+s1[1];
	x=s2[0]+s2[1];
	
	if(c1==c2){
		if(r==x){
			row=1;
			if((s1[2]=='F') || (s1[2]=='D')) side_r = 1;
			else side_r = 2;
			
			if((s2[2]=='F') || (s2[2]=='D')) side_x = 1;
			else side_x = 2;
			
			if(side_r==side_x) side = 1;
			if(abs(s1[2]-s2[2])==1 && side_r==side_x) nex=1;
		}
    }
	
	cout << (c1==c2);
	cout << row;
	cout << side;
	cout << nex;
	
	return 0;
}
