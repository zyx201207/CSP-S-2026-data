#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
string c1,s1,c2,s2;
int flag=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(flag&&((c1[0]-'0')*10+c1[1]-'0'==(c2[0]-'0')*10+c2[1]-'0')){cout<<1; flag=1;}
	else{cout<<0; flag=0;}
	if(flag&&((s1[0]-'0')*10+s1[1]-'0'==(s2[0]-'0')*10+s2[1]-'0')){cout<<1; flag=1;}
	else{cout<<0; flag=0;}
	if(flag){
		if(s1[2]=='F'||s1[2]=='D'){
			if((s2[2]=='D'||s2[2]=='F')&&s2[2]!=s1[2]){
				cout<<1;
				flag=325325;
			}else{
				cout<<0;
				flag=0;
			}
		}else{
			if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&s2[2]!=s1[2]){
				cout<<1;
				flag=799799;
			}else{
				cout<<0;
				flag=0;
			}
		}
	}else cout<<0;
	if(flag==325325) cout<<1;
	else if(flag==799799&&(s1[2]=='B'||s2[2]=='B')) cout<<1;
	else cout<<0;
	return 0;
}
