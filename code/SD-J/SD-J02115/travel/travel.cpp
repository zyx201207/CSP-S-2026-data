#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[20],b[20];
int cnt,cnt2;
char sa,sb;
bool f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]>'0'&&s1[i]<='9'){
			a[++cnt]=s1[i]-'0';
		}
		if(s2[i]>'0'&&s2[i]<='9'){
			b[++cnt2]=s2[i]-'0';
		}
	}
	sa=s1[2];
	sb=s2[2];
	if(cnt!=cnt2){
		cout<<"1000";
		return 0;
	}
	else{
		for(int i=1;i<=cnt;i++){
			if(a[i]!=b[i]){
				cout<<"1000";
				return 0;
			}
		}
		cout<<"11";
		if(sa=='A'&&sb=='B'||sa=='A'&&sb=='C'||sa=='B'&&sb=='c'||sa=='B'&&sb=='A'||sa=='C'&&sb=='A'||sa=='C'&&sb=='B'||sa=='D'&&sb=='F'||sa=='F'&&sa=='D'){
			cout<<"1";
			if(sa=='A'&&sb=='B'||sa=='B'&&sb=='A'||sa=='B'&&sb=='C'||sa=='D'&&sb=='F'||sa=='F'&&sa=='D'){
				cout<<"1";
				return 0;
			}
			else{
				cout<<"0";
				return 0;
			}
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	return 0;
} 
