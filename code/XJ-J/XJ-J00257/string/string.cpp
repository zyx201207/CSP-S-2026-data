#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1;i <= n;i++){
		int num;
		cin >> num;
		cin >> s;
		sum += num;
	}
	cout << sum/2;
	return 0;
}