#include<bits/stdc++.h>
using namespace std;
int s[1000000];
int main(){
	fropen("and.in","r",stdin);
	fropen("and.out","w",stdout);
	int a,d;
	cin >> a >> d;
	for(int i = 1;i <= a;i++){
		cin >> s[i];
	}
	sort(s+1,s+a+1);
	cout << s[d];
	return 0;
}
