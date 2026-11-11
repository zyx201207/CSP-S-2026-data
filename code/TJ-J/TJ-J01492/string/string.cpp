#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s;
	int p=0;
	while(n--){
		int m;
		string ss;
		cin>>m>>ss;
		for(int i=1;i<=m;i++){
			s=s+ss;
		}
		p+=m;
	}
	int cnt=0;
	for(int i=0;i<=p/2-1;i++){
			if(s[i]!=s[p-i-1]){
				cnt++;
			}
	}
	cout<<cnt;
	//zzy
	return 0;
} 
