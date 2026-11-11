#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt=0;
stack<char>st;
signed main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	cin>>n;
	string a="";
	while(n--){
		int x;
		char y;
		cin>>x>>y;
		while(x--){
			a+=y;
			st.push(y);
		}
	}
	for(int i=0;i<st.size();i++){
		if(st.top()!=a[i]){
			cnt++;
		}
		st.pop();
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
