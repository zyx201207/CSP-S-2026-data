#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		long long num;
		string m;
		cin >> num >> m;
		while(num--){
			s+=m[0];
		}
	}
	long long cnt=0;
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
