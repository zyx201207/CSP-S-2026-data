#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a,b,c,d,x,y;
char u,v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a != c){
		cout << "0000";
	}
	else 
	{
		u = b[2] , v = d[2];
		int size_B = b.size();
		int size_D = d.size();
		for(int i = 0 ; i < size_B - 1; i ++)
		{
			x += b[i];
		}
		for(int i = 0 ; i < size_D - 1; i ++)
		{
			y += d[i];
		}
//		cout << x <<' '<<y<<endl;
		if(x != y)
		{
			cout << "1000";
		}
		else
		{
			if(u >='A' && u <= 'C'){
				if(v >='A' && v <= 'C'){
					if(abs(int(u)-int(v)) == 1){
						cout << "1111";
					}else{
						cout <<"1110";
					}
				}else{
					cout <<"1100"; 
				}
			}else{
				if(v == 'D' || v == 'F')
				{
					if(abs(int(u)-int(v)) == 2){
						cout << "1111";
					}else{
						cout <<"1110";
					}
				}else{
					cout <<"1100";
				}	
			}
		}
	}
	return 0;
}
