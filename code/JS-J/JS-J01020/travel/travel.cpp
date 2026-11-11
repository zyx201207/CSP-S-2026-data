#include <bits/stdc++.h>
//一眼红 秒了
//wbxl密码居然是Trick||Treat! 看来ccf换了年轻员工（
using namespace std;
int c1,c2;
char s1[15],s2[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> (s1+1);
	cin >> c2 >> (s2+1);
	//cout << c1 << ' ' << c2 << '\n';
	if(c1!=c2){
		cout << "0000";
		return 0;
	}
	cout << 1;
	int p1=(s1[1]-'0')*10+(s1[2]-'0');
	int p2=(s2[1]-'0')*10+(s2[2]-'0');
	//cout << p1 << ' ' << p2;
	if(p1!=p2){
		cout << "000";
		return 0;
	}
	cout << 1;
	int st1=s1[3]-'A',st2=s2[3]-'A';
	//？谁在吃费列罗 好香
	if((st1<3&&st2>=3)||(st1>=3&&st2<3)){
		cout << "00";
		return 0;
	}
	cout << 1;
	if(abs(st1-st2)==1||((st1==3&&st2==5)||(st1==5&&st2==3)))cout << 1;
	else cout << 0;
	return 0;
}
