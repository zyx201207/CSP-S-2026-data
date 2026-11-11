#include<iostream>
#include<string>
using namespace std;

string c1,c2,s1,s2;
bool yipai,chexiang,tongce;
int main(){
	freopen("travel.in","r",stdin);
	freopen("treavel.out","w",stdout);
	cin >> c1 >> c2 >> s1 >> s2;
	if(c1 == s1){//是否在同一个车厢 
		cout << 1;
		chexiang = 1;
	}
	else cout << 0;
	if(c2[0] == s2[0] && c2[1] == s2[1] && chexiang == 1){//是否在同一排 
		cout << 1;
		yipai = 1;
	}
	else cout << 0;
	if((c2[2]=='A' || c2[2]=='B' || c2[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C') && c2[2] != s2[2] && chexiang ==1&&yipai==1)//是否在同一侧 
	{
		cout << 1;
		tongce = 1;	
	}
	else if((c2[2]=='D' || c2[2]=='F') && (s2[2]=='D' || s2[2]=='F') && c2[2] != s2[2] && chexiang ==1&&yipai==1){
		cout << 1;
		tongce = 1;
	}
	else cout << 0;
	if((c2[2] + 1 == s2[2] || s2[2] - 1 == s2[2]) && !(s2[2] + 1 == 'D' || s2[2] - 1 == 'C') && chexiang ==1&&yipai==1 && tongce==1) cout << 1;
	else if((c2[2] == 'D' || c2[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F') && chexiang ==1&&yipai==1 && tongce==1) cout << 1;
	else cout << 0;
	return 0;
} 
// 1111 vs 1100?
