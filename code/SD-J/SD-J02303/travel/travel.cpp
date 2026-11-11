#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
	}
	if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		b=1;
	}
	n=s1[2]-'A'+1;
	m=s2[2]-'A'+1;
	if(n<m){
		swap(n,m);
	}
	if(a==1&&b==1){
		if(n==1||n==2||n==3){
			if(m==1||m==2||m==3){
				c=1;
			}
		}else if(n==4||n==5){
			if(m==4||m==5){
				c=1;
			}
		}
	}
	if(b==1&&c==1){
		if(n-m==1){
			d=1;
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
