#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c3){
		printf("1");
		if(c2[0] == c4[0] && c2[1] == c4[1]){
			printf("1");
			int id1 = c2[2] - 'A',id2 = c4[2] - 'A';
//			printf("\n%d %d",id1,id2);
			if((id1 <= 2 && id2 <= 2) || (id1 > 2 && id2 > 2)){
				printf("1");
				if(abs(id1 - id2) == 1) printf("1");
				else printf("0");
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	return 0;
}
