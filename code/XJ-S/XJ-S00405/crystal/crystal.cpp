#include<bits/stdc++.h>
using namespace std;
int q[110];
int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int a , s;
	cin >> a >> s;
	for(int i = 1;i <= a;i++){
		cin >> q[i];
	}

	int d = 0;
	for(int i = 1;i <= s;i++){
		if(q[1] == q[1+1]){
			q[1] = q[1] - q[1];
			d++;
		} else {
			q[1] = q[1] + 1;
		}
	}
	cout << d+1;
	return 0;
}
