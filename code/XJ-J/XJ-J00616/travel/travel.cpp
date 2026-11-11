#include <bits/stdc++.h>
using namespace std;
int a , b , flag1 , flag2 , flag3 , flag4;
string aa , bb;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin>>a>>aa>>b>>bb;
	if(a == b){
		flag1 = 1;
		if(aa[0] == bb[0] && aa[1] == bb[1]){
			flag2 = 1;
			int pos_a = aa[2] - 'A'; // 0 , 1 , 2 ,    3 -> 4 , 5
			int pos_b = bb[2] - 'A';
			if((pos_a <= 2 && pos_b <= 2) || (pos_a >= 3 && pos_b >= 3)){
				flag3 = 1;
				pos_a = (pos_a == 3 ? 4 : pos_a);
				pos_b = (pos_b == 3 ? 4 : pos_b);
				if(abs(pos_a - pos_b) == 1){
					flag4 = 1;
				}
			}
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
