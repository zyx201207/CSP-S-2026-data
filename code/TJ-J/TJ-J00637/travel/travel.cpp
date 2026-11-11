#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		int a1=s1[0]-'0'*10+s1[1]-'0',b1=s2[0]-'0'*10+s2[1]-'0';
		if(a1==b1){
			cout<<1;
			char a2=s1[2],b2=s2[2];
			if((a2=='F' and b2=='D') or (a2=='D' and b2=='F') or (a2=='A' and (b2=='B' or b2=='C')) or (a2=='B' and (b2=='A' or b2=='C')) or (a2=='C' and (b2=='B' or b2=='A'))){
				cout<<1;
				if((a2=='F' and b2=='D') or (a2=='D' and b2=='F') or (a2=='A' and b2=='B') or (a2=='B' and (b2=='A' or b2=='C')) or (a2=='C' and b2=='B')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
				}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
