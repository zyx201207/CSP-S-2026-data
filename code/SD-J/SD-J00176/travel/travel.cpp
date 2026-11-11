#include<bits/stdc++.h>
#include<cstdio>
#define int long long
#define endl '\n'
#define Fre
#define Ct

const int N=1e5+10;

using namespace std;

typedef pair<int,int> PII;

void solve(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return;
	}
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			cout<<"1000"<<endl;
			return;
		}
	}
	if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'){
		if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'){
			cout<<"1111"<<endl;
			return;
		}
		else if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
			cout<<"1111"<<endl;
			return;
		}
		else{
			cout<<"1110"<<endl;
			return;
		}
	}
	else{
		cout<<"1100"<<endl;
		return;
	}
}

signed main(){
	
#ifdef Fre
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
#endif

#ifdef Ct
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int _=1;
	//cin>>_;
	while(_--) solve();
	
	return 0;
}
