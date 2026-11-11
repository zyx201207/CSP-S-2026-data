#include <bits/stdc++.h> 
using namespace std;
string s,p="1",c;
int n,x,num=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("strint.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> x >> c;
		for (int j=1;j<=x;j++){
			s+=c;
		}
	}
	for (int i=0;i<=s.length()/2;i++){
		if (s[i]!=s[s.length()-i-1]){
				num++;
		}
	}
	cout << num;
}
