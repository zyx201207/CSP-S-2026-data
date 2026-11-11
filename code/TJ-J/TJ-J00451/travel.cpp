#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
string car1,ren1,car2,ren2;
cin >> car1 >> ren1 >> car2 >> ren2;
bool same_car=(car1==car2);
char ch1 = ren1[ren1.size()-1];
string row1 = ren1.substr(0,ren1.size()-1);
char ch2 = ren2[ren2.size()-1];
string row2 = ren2.substr(0,ren2.size()-1);
bool same_row=same_car&&(row1==row2);
bool same_side=false;
if(same_row){
	bool l1=(ch1=='A'||ch1=='B'||ch1=='C');
	bool l2=(ch2=='A'||ch2=='B'||ch2=='C');
	same_side=(l1=l2);
}
string order = "ABCDF";
bool beside = false;
if(same_row){
	int p1 = order.find(ch1);
	int p2 = order.find(ch2);
	if(abs(p1-p2)==1){
		beside = true;
	}
}
cout << (same_row?'1':'0');
cout << (same_car?'1':'0');
cout << (same_side?'1':'0');
cout << (beside?'1':'0');
 return 0;
}
