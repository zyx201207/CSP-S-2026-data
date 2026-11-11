#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int s;
	string t;
	int c;
	string a;
	int an = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> c >> t;
		for(int j = 0;j < c;j++){
			a += t;
		}
		s += c;
		t = "";
		c = 0;
	}
	for(int i = 0;i < s/2;i++){
		if(a[i] != a[s-i-1]){
			an++;
		}	
	}
	cout << an;
	return 0;
	fclose(stdin);
	fclose(stdout);
}