#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,c="csp",d="ioi";
	long long a,b,l=0,cnt1=0,cnt2=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b>>s;
		if(i==1){
			c=s;
		}
		if(s!=c){
			if(d=="ioi"||d==s){
				l=2;
				d=s;
				cnt2+=b;
			}
		}else{
			cnt1+=b;
		}
	}
	if(l==2){
		cout<<min(cnt1,cnt2);
	}else{
		cout<<0;
	}
}
