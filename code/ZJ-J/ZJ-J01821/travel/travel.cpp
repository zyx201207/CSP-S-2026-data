/**
人生几十年总会有风雨来陪
潇潇洒洒赴会今不醉不归
往事后不后悔慢慢去体会
此刻朋友这杯酒最珍贵 

快把酒满上干了这杯大声歌唱
好朋友好朋友今宵多欢唱
理想改变了我们的模样
也让我懂得了要珍惜朋友的肩膀 

阳光总会在风雨之后洒向苍茫
让我们抬起头学会了坚强
就像朋友的一杯热酒烫我心上
温暖我凡事别再放心上 

——《朋友的酒》 
**/
#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;

bool check(){
	int i1,i2;
	i1=b[0]-'0'*10+b[1]-'0';
	i2=d[0]-'0'*10+d[1]-'0';
	if(abs(i1-i2)==0){
		if(abs(b[2]-d[2])==1 && !((b[2]=='C' && d[2]=='D') || (d[2]=='C' && b[2]=='D'))) return true;
	}
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>a>>b>>c>>d;
	
	if(a==c){
		cout<<"1";
		if(b[0]==d[0] && b[1]==d[1]){
			cout<<"1";
			if((b[2]=='A' && d[2]=='B') ||
			   (b[2]=='A' && d[2]=='C') ||
			   (b[2]=='B' && d[2]=='A') ||
			   (b[2]=='B' && d[2]=='C') ||
			   (b[2]=='C' && d[2]=='A') ||
			   (b[2]=='C' && d[2]=='B') ||
			   (b[2]=='D' && d[2]=='F') ||
			   (b[2]=='F' && d[2]=='D')){
				cout<<"1";
				if(check()){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	
	
	
	
	return 0;
}
