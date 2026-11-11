#include<iostream>
#include<cmath>
using namespace std;
bool left(char c){
	if(c=='A'||c=='B'||c=='C') return 1;
	return 0;
}
int change(char c){
	if(c=='A') return 1;
	if(c=='B') return 2;
	if(c=='C') return 3;
	if(c=='D') return 5;
	if(c=='F') return 6;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			bool f1=left(b[2]),f2=left(d[2]);
			if((f1&&f2)||(!f1&&!f2)){
				cout<<"1";
				if(abs(change(b[2])-change(d[2]))==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
两张车票对应的座位是否在同一节车厢；
两张车票对应的座位是否在同一节车厢的同一排；
两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧，且在该侧的座位序列中相邻。
*/
