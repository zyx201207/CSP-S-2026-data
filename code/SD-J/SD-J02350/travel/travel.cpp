#include<iostream>
#include<cstdio>
using namespace std;
string c1,c2,s1,s2;
int cnt;
bool panduan(char a,char b){
	if(a<='C'&&a>='A'&&b<='C'&&b>='A') return 1;
	if(a<='F'&&a>='D'&&b<='F'&&b>='D') return 1;
	return 0;
}
bool panduan2(char a,char b){
	if(a=='D'&&b=='F'||a=='F'&&b=='D') return 1;
	if(a=='A'&&b=='B'||a=='B'&&b=='A') return 1;
	if(a=='B'&&b=='C'||a=='C'&&b=='B') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		cnt++;
		if(c2[0]+c2[1]==s2[0]+s2[1]){
			cout<<1;
			cnt++;
			if(panduan(c2[2],s2[2])){
				cout<<1;
				cnt++;
				if(panduan2(c2[2],s2[2])){
					cout<<1;
					cnt++;
				}
				else{
					cout<<0;
					cnt++;
				}
			}
			else{
				cout<<0;
				cnt++;
			}
		}
		else{
			cout<<0;
			cnt++;
		}
	}
	else{
		cout<<0;
		cnt++;
	}
	if(cnt!=4){
		for(int i=1;i<=4-cnt;i++){
			cout<<0;
		}
	}
	return 0;
} 
