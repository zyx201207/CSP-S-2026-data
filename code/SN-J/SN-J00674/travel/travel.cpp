//kao hao:SH-J00674   xing ming:wang ge   xue xiao:yan an pei zhi zhong xue
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],s1[3],c2[2],s2[3];
	cin>>c1>>s1>>c2>>s2;
	int p1,p2;
	if(c1[0] == '0'){
		p1 = char(c1[1]) - '0';
	}else{
		p1 = char(c1[1]) - '0' + 10;
	}
	if(c2[0] == '0'){
		p2 = char(c2[1]) - '0';
	}else{
		p2 = char(c2[1]) - '0' + 10;
	}
	if(p1 == p2 && p1 != 1 && p1 != 16){
		int o1,o2;
		if(s1[0] == '0'){
			o1 = char(s1[1]) - '0';
		}else{
			o1 = char(s1[1]) - '0' + 10;
		}
		if(s2[0] == '0'){
			o2 = char(s2[1]) - '0';
		}else{
			o2 = char(s2[1]) - '0' + 10;
		}
		if(o1 == o2){
			char l1,l2;
			l1 = s1[2];
			l2 = s2[2];
			if((l1 == 'A' || l1 == 'B' || l1 == 'C') && (l2 == 'A' || l2 == 'B' || l2 == 'C')){
				if((l1 == 'A' && l2 == 'B')||
				(l1 == 'B' && l2 == 'A')||
				(l1 == 'B' && l2 == 'C')||
				(l1 == 'C' && l2 == 'B')||
				(l1 == 'D' && l2 == 'F')||
				(l1 == 'F' && l2 == 'D')){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else if((l1 == 'D' || l1 == 'F') && (l2 == 'D' || l2 == 'F')){
				if((l1 == 'A' && l2 == 'B')||
				(l1 == 'B' && l2 == 'A')||
				(l1 == 'B' && l2 == 'C')||
				(l1 == 'C' && l2 == 'B')||
				(l1 == 'D' && l2 == 'F')||
				(l1 == 'F' && l2 == 'D')){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
