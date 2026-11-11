#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long cnt=1;
char x1,x2,x3,x4,x5,x6;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x1>>x2>>x3>>m>>x4>>x5>>x6;
	if(n!=m){
		cnt=0;
	}
	cout<<cnt;
	if(x1!=x4||x2!=x5){
		cnt=0;
	}
	cout<<cnt;
	if(x3=='A'||x3=='B'||x3=='C'){
		if(x6=='A'||x6=='B'||x6=='C'){
			cout<<cnt;
			long long ans=abs(x3-x6);
			if(ans==1){
				cout<<cnt;
			}else{
				cout<<0;
			}
			return 0;
		}
		cout<<0<<0;
		return 0;
	}else{
		if(x6=='D'||x6=='F'){
			cout<<cnt<<cnt;
			return 0;
		}
		cout<<0<<0;
		return 0;
	}
	return 0;
}
