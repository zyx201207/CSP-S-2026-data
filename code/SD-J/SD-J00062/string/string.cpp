#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long mid=0,lenn=0;
	for(int i=1;i<=n;i++){
		int x;
		string xs;
		cin>>x>>xs;
		mid+=x;
		lenn+=x;
		while(x--){
			s+=xs;
		}
	}
	if(mid%2==0){
		mid/=2;
	}else{
		mid/=2;
		s.erase(mid+1,1);
		lenn--;
	}
	long long ans=0;
	for(long long i=0;i<mid;i++){
		if(s[i]!=s[lenn-i-1]) ans++;
	}
	cout<<ans;
	return 0;
} 
