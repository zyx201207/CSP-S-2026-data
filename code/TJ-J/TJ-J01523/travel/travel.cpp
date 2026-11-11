#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string a1;
	string b;
	string b1;
	cin>>a>>a1>>b>>b1;
	int cnt =0;
	
	if(a1[2]=='D'){
		a1[2]+=3;
	}
	if(b1[2]=='D'){
		b1[2]+=3;
	}
	int n=abs(a1[2]-b1[2]);
	string s="0000";
	if(a==b){
		cnt+=1000;
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			cnt+=100;
			if(n==1||n==2){
				cnt+=10;
				if(n==1){
					cnt+=1;
					cout<<cnt;
				}else{
					cout<<cnt;
					return 0;
				}
			}else{
				cout<<cnt;
				return 0;
			}
		}else{
			cout<<cnt;
			return 0;
		}
	}else{
		cout<<s;
		return 0;
	}
	
	
	return 0;
}
