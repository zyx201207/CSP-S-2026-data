#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
//能满分吧...应该吧 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	//同车 
	if(c1==c2){
		cout << '1';
	}else{
		cout << '0';
	//同车 + 同排 
	}if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout << '1';
	}else{
		cout << '0';
	}
	//同车 + 同排 +同侧 
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		int x,y;
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			x=1;
		}else{
			x=2;
		}if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			y=1;
		}else{
			y=2;
		}
		if(x==y){
			cout << '1';
			//一些判定 
			if(x==1){
				if(s1[2]=='A'){
					if(s2[2]=='B'){
						cout << '1';
					}else{
						cout << '0';
					}
				}else if(s1[2]=='B'){
					//同侧的中间必定相邻 
						cout << '1';
				}if(s1[2]=='C'){
					if(s2[2]=='B'){
						cout << '1';
					}else{
						cout << '0';
					}
				}
			}else if(x==2){
				//已经同侧，在右边必定相邻 
				cout << '1';
			}
		}else{
			cout << '0' << '0';
		}
	}
	else{
		cout << '0' << '0'; 
	} 
	//输出0兜底，防止缺少答案 
	return 0; 
}
