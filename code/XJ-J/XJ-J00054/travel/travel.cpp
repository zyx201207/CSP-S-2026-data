#include<bits/stdc++.h>
using namespace std;
struct node{
	string id;
	string s;
}a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a.id >> a.s >> b.id >> b.s;
	int id1=0,id2=0;
	for(int i=0;i<=1;i++){
		id1*=10;
		id2*=10;
		id1+=a.id[i]-'0';
		id2+=b.id[i]-'0';
	}
	int s1=0,s2=0;
	for(int i=0;i<=1;i++){
		s1*=10;
		s2*=10;
		s1+=a.s[i]-'0';
		s2+=b.s[i]-'0';
	}
	char n1=a.s[2],n2=b.s[2];
	if(id1==id2){
		cout << 1;
		if(s1==s2){
			cout << 1;
			if((n1=='A'||n1=='B'||n1=='C')&&(n2=='A'||n2=='B'||n2=='C')){
				cout << 1;
				if(n1=='C') cout << (n2==n1-1)?1:0;
				else if(n2=='C') cout << (n1==n2-1)?1:0;
				else cout << (n1==n2+1||n1==n2-1)?1:0;
			}
			else cout << "00";
			
		}
		else cout << "000";
	}
	else cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
