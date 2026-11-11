#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--) s+=c; 
	}
	int len=s.size();
	int i=0,j=len-1;
	while(i<=j){
		if(s[i]!=s[j]) cnt++;
		i++;
		j--;
	}
	cout<<cnt;
	return 0;
} 
