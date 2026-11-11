#include<bits/stdc++.h>
using namespace std;

bool memjfs;
long long n,ansl=0,ansr=0;
string s,t;
bool jug(){
	reverse(s.begin(),s.end());
	t=s;
	reverse(s.begin(),s.end());
	return t==s;
}
bool memjff;

int main(){
//	printf("%.8lfMB\n",(&memjff-&memjfs)/1024.0/1024.0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	
	char xxx;
	for(long long i=1,x;i<=n;i++){
		cin>>x>>xxx;
		
		for(long long j=1;j<=x;j++){
			s+=xxx;
		}
	}
	
	if(jug()){
		cout<<0;
		return 0;
	}
	
	for(long long i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i+1]){
			ansl++;
		}
	}
	
	for(long long i=s.length()-1;i>s.length()/2;i--){
		if(s[i]!=s[s.length()-i-1]){
			ansr++;
		}
	}
	
	cout<<min(ansl,ansr);
	return 0;
}
