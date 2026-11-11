#include<bits/stdc++.h>
using namespace std;
int cnt=0;
//小R a节，c号
//小X b节，d号
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	for(int i=1;i<=c.size();i++){
		for(int j=1;j<=d.size();j++){
			if(a==b){
				cnt=1;
			}else{
				cnt==0000;
			}//两张车票对应的座位是否在同一节车厢
			if(cnt==0000){
				cout<<cnt;
				break;
			}//若是0000，停止 
			if(c[1]==d[1]&&c[2]==d[2]){
			    cnt=cnt+10;
			}//两张车票对应的座位是否在同一节车厢
			if(c[3]=='F'||c[3]=='D'&&d[3]=='F'||d[3]=='D'){
				cnt=cnt+100;
			}else if(c[3]=='A'||c[3]=='B'||c[3]=='C'&&d[3]=='A'||d[3]=='B'||d[3]=='C'){
				cnt=cnt+100;
			}//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
			if(c[2]==d[2]&&c[1]==d[1]&&c[3]=='F'&&d[3]=='D'||c[3]=='D'&&d[3]=='F'||c[3]=='C'&&d[3]=='B'||c[3]=='B'&&d[3]=='C'||c[3]=='A'&&d[3]=='B'||c[3]=='B'&&d[3]=='A'){
				cnt=cnt+1000;
			}//两张车票对应的座位是否相邻
    	}	
	}
	cout<<cnt;
	return 0;
}
