#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string cx,sx,cy,sy;
	cin>>cx>>sx>>cy>>sy;
	string fir="";
	string sec="";
	fir+=sx[0];
	fir+=sx[1];
	sec+=sy[0];
	sec+=sy[1];
	char fnd=sx[2];
	
	char snd=sy[2];
	
	if(cx!=cy){
		cout<<"0000";
		return 0;
	}
	else if(fir!=sec){
		cout<<"1000";
		return 0;
	}
	else if(!((int(fnd)<=int('C')&&int(snd)<=int('C'))||(int(fnd)>=int('D')&&int(snd)>=int('D')))){
		cout<<"1100";
		return 0;
	}
	else if(abs(int(fnd)-int(snd))!=1){
		cout<<"1110";
		return 0;
	}
	else cout<<"1111";
	return 0;
} 
