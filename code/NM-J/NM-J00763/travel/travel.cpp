#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string sa,sb;
	cin>>n>>sa>>m>>sb;

	int sai = (sa[0]-'0')*10+(sa[1]-'0');
	char sac=sa[2];
	int sbi = (sb[0]-'0')*10+(sb[1]-'0');
	char sbc=sb[2];

	if(n==m){
		cout<<1;
	}
	else{
		cout<<0;
	}

	if(n==m && sai==sbi){
		cout<<1;
	}
	else{
		cout<<0;
	}

	if(n==m && sai==sbi){
		if(sac=='A' || sac=='B' || sac=='C'){
			if(sbc=='A' || sbc=='B' || sbc=='C'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		if(sac=='D' || sac=='E'){
			if(sbc=='D' || sbc=='E'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	else{
		cout<<0;
	}


	if(n==m && sai==sbi){
		if(sac=='A' && sbc=='B'){
			cout<<1;
			return 0;
		}
		if(sac=='B' && sbc=='C'){
			cout<<1;
			return 0;
		}
		if(sac=='B' && sbc=='A'){
			cout<<1;
			return 0;
		}
		if(sac=='C' && sbc=='B'){
			cout<<1;
			return 0;
		}
		if(sac=='D' && sbc=='E'){
			cout<<1;
			return 0;
		}
		if(sac=='E' && sbc=='E'){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
