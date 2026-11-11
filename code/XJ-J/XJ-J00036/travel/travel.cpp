#include<bits/stdc++.h>
using namespace std;
bool b[4];
int q,p,n,m;
string s1,s2;
char ch1,ch2;
int main(){
	preopen("travel.in","r",stdin);
	preopen("travel.out","w",stdout);
	cin>>q>>s1>>p>>s2;
	n = s1[0]-'0'+s1[1]-'0';
	m = s2[0]-'0'+s2[1]-'0';
	ch1 = s1[2];
	ch2 = s2[2];
	if(q==p){
		if(n==m){
			b[2]==1;
			if(ch1>=65 && ch1<=67  && ch2>=65 && ch2<=67){
				b[3] = 1;
				if(ch1+1 == ch2){
					cout<<1111; 
					return 0;
				}
				if(ch1-1 == ch2){
					cout<<1111; 
					return 0;
				}
				else{
					cout<<1110; 
					return 0;
				}
			}else if((ch1>=68 && ch1 <= 69) && (ch2>=68 && ch2<=69)){
				if(ch1+1 == ch2){
					cout<<1111;
					return 0;
				}
				else if(ch1-1 == ch2){
					cout<<1111;
					return 0;
				}
				else{
					cout<<1110;
					return 0;
				}
			}else{
				cout<<1100;
				return 0;
			}
		}else{
			cout<<1000;
			return 0;
		}
	}
	cout<<0<<0<<0<<0;
	return 0;
} 
