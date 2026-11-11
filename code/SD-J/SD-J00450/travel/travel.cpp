//travel
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a1[1000] , a2[1000];
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	a1[int('F')] = 'D';
	a1[int('D')] = 'F';
	a1[int('C')] = 'B';
	a1[int('B')] = 'C';
	a1[int('B')] = 'A';
	a1[int('A')] = 'B';
	a2[int('C')] = 'A';
	a2[int('A')] = 'C';
	int r1 , x1 , r2 , x2;
	char r3 , x3;
	cin >> r1 >> r2 >> r3;
	cin >> x1 >> x2 >> x3;
	if (r1==x1){
		cout<<1;
		if(r2==x2){
			cout<<1;
			if(a1[int(r3)]==x3||a2[int(r3)]==x3){
				cout<<1;
				if(a1[int(r3)]==x3){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
