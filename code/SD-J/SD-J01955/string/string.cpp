//I love CCF.
//Please give me more points.
#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
string s;
int chang(int q){
	if(q%2==1){
		return (q+1)/2;
	}
	else{
		return q/2;
	}
}
int num,n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<chang(s.size());i++){
		if(s[i]!=s[s.size()-i-1]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
