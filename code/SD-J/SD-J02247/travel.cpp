#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in ","r",stdin);
	freopen("travel.out ","w",stdout);/////////
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	int h=1,p=1;
	for(int i=0;i<max(s1.size(),c1.size());i++){
		if(s1[i]!=c1[i]) h=0;
	}
	for(int i=0;i<2;i++){
		if(s2[i]!=c2[i]) p=0;
	}
	int k=0,l=0;
	if(p==1){
//		if(s2[2]=='F'&&c2[2]=='D'){
//			k=1;	
//		} 
//		else if(s2[2]=='D'&&c2[2]=='F'){
//			k=1;
//		}
		if(s2[2]=='D'||s2[2]=='F'){
			if(c2[2]!='A'&&c2[2]!='B'&&c2[2]!='C') k=1;
		}
		else if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C') k=1;
	}
	cout<<h<<p<<k;
	if(abs((s2[2]-'0')-(c2[2]-'0'))==1){
		if(s2[2]=='C'&&c2[2]=='D'){
			cout<<0;
			return 0;
		}
		else if(s2[2]=='D'&&c2[2]=='C'){
			cout<<0;
			return 0;
		}
		else{
			if(s2[2]=='F'||s2[2]=='D'){
				if(c2[2]!='F'&&c2[2]!='D'){
					cout<<0;
					return 0;
				}
			}
		}
		cout<<1;
	}
	if(abs((s2[2]-'0')-(c2[2]-'0'))!=1){
		cout<<0;
		return 0;
	}

	return 0;
} 
