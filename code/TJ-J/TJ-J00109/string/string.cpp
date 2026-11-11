#include <bits/stdc++.h>
using namespace std;
int num;
string s1;
string s;
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		int a;
		cin >> a;
		num+=a;
		cin >> s1;
		for(int j=0;j<a;j++){
			s += s1;
		} 
	} 
	int l=0,t=num-1;
	for(int x=1;x<=num;x++){
		if(l>t){
			break;
		}
		if(s[l] != s[t]){
			cnt++;
		} 
		l+=1;
		t-=1;
		
	}
	cout << cnt;
	
	return 0;
}
