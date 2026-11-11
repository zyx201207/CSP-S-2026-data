#include<bits/stdc++.h>
using namespace std;
bool isst(string st){
	int m1=st.size();
	if(m1%2==0){
		int k1=m1/2;
		for(int i=0;i<k1;i++){
			if(st[i]!=st[m1-i-1]){
				return 0;
			}
		}
		return 1;
	}else if(m1%2!=0){
		int k1=(m1+1)/2;
		for(int i=0;i<k1;i++){
			if(st[i]!=st[m1-i-1]){
				return 0;
			}
		}
		return 1;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,y=0,yy=0,pp;
	char p;
	string s="",st="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		if(i==1||p==c){
			y++;
		}
		if(i==1||pp==a){
			yy++;
		}
		for(int j=1;j<=a;j++){
			s+=c;
		}
		st+=c;
		p=c;
		pp=a;
	}
	if(y==n){
		cout<<0;
		return 0;
	}
	if(pp==n&&isst(st)){
		cout<<0;
		return 0;
	}
	int m=s.size(),cnt=0;
	if(m%2==0){
		int k=m/2;
		for(int i=0;i<k;i++){
			if(s[i]!=s[m-i-1]){
				cnt++;
			}
		}
	}else if(m%2!=0){
		int k=(m+1)/2;
		for(int i=0;i<k;i++){
			if(s[i]!=s[m-i-1]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
