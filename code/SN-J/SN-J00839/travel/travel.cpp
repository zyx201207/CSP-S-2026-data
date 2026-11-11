//姓名:陆坦仪
//考号:SN-J00839
//学校:西安市第三中学 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans[10] = {};
bool check(string x,string y){
	if(x[2] <= 'C' && x[2] >= 'A'){
		if(y[2] <= 'C' && y[2] >= 'A'){
			return true;
		}else{
			return false;
		}
	}
	if(x[2] <= 'F' && x[2] >= 'D'){
		if(y[2] <= 'F' && y[2] >= 'D'){
			return true;
		}else{
			return false;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		//1.是否在同一车厢 
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			//2.是否在同一排 
			cout << "1";
			if(check(s1,s2)){
				//3.是否在同一侧
				cout << "1";
				if(s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]){
					//4.
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			//不在同一排 则一定不可能相邻 
			cout << "000";
		}
	}else{
		//不在同一车厢 则全都不可能满足 
		cout << "0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
