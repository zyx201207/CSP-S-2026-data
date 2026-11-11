#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a[5]={0};
	if(c1==c2){
		a[1]=1;
		int b=0,c=0;
		b+=(s1[0]-'0')*10+s1[1]-'0';
		c+=(s2[0]-'0')*10+s2[1]-'0';
		if(b==c){
			a[2]=1;
			char n,m;
			n=s1[2];
			m=s2[2];
			if(((n=='A'||n=='B'||n=='C')&&(m=='D'||m=='F'))||((n=='D'||n=='F')&&(m=='A'||m=='B'||m=='C'))){
				cout<<"1100";
				return 0;
			}else{
				if(n=='A'){
					if(m=='B'){
						cout<<"1111";
						return 0;
					}else{
						cout<<"1110";
						return 0;
					}
				}else if(n=='B'){
					if(m=='A'||m=='C'){
						cout<<"1111";
						return 0;
					}else{
						cout<<"1110";
						return 0;
					}
				}else if(n=='C'){
					if(m=='B'){
						cout<<"1111";
						return 0;
					}else{
						cout<<"1110";
						return 0;
					}
				}else if(n=='D'||n=='F'){
					if(m=='D'||m=='F'){
						cout<<"1111";
						return 0;
					}else{
						cout<<"1110";
						return 0;
					}
				}
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
