#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,s2;
vector<pair<int,char>>v,v2,vl;
int n,cnt;
bool b,b2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(/*n<=2000*/true){
		for(int i=1;i<=n;i++){
			int x;
			char y;
			cin>>x>>y;
			vl.push_back({x,y});
			if(/*x<=500*/true){
				for(int j=1;j<=x;j++){
					s.push_back(y);
				}
				b=true;
			}else{
				if(x>500&&vl[i-2].first==x){
					b2=false;
				}else{
					b2=true;
				}
			}
		}
		if(!b2){
			for(int i=0;i<(int)vl.size();i++){
				v.push_back(vl[i]);
			}
			b=false;
		}
	}else{
		
	}
	if(n<=1){
		cout<<0;
	}else if(/*n<=2000*/true){
		if(b){
			s2=s;
			reverse(s2.begin(),s2.end());
			for(int i=0;i<(int)s.size()/2;i++){
				if(s2[i]!=s[i]){
					s2[i]=s[i];
					cnt++;
				} 
			}
			/*
			for(int i=(int)s.size()/2;i<(int)s.size();i++){
			if(s2[i]!=s[i]) cnt++;
			}
			*/
		}else{
			v2=v;
			reverse(v2.begin(),v2.end());
			for(int i=0;i<(int)v.size()/2;i++){
				if(v2[i]!=v[i]){
					v2[i]=v[i];
					cnt+=v[i].first;
				} 
			}
		}
		cout<<cnt;
	}
	return 0;
}
