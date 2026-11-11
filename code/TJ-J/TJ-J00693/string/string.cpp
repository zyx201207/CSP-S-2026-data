#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,st,ov,cnt,shs,ks,ko,yt,alll,tc=1,sho;
char blll;
ll a[300000];
char b[300000];
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>alll>>blll;
		if(blll==b[tc-1]){
			a[tc-1]+=alll;
		}
		else{
			a[tc]=alll;
			b[tc]=blll;
			tc++;
		}
	}
	st=1;
	tc--;
	ov=tc;
	shs=a[st];
	sho=a[ov];
	while(st<ov){

		if(shs>=sho){
			shs-=sho;
			if(b[st]!=b[ov])	cnt+=sho;
			ov--;
			sho=a[ov];
		}
		else{
			sho-=shs;
			if(b[st]!=b[ov]) cnt+=shs;
			st++;
			shs=a[st];
		}
	}
	cout<<cnt;
	return 0;
} 

