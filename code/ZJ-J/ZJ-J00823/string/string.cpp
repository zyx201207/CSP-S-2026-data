#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	string a;
	for(int i = 1;i <= n;i++){
		int n1;cin >> n1;
		char c1;cin >> c1;
		for(int j = 1;j <= n1;j++){
			a+=c1;
		}
	}
	bool b = 0;
	int t = a.length();
	if(t % 2 == 0){
		for(int i = 0;i < t / 2;i++){
			if(a[i]!=a[t-i-1]){
				b = 1;
				break;
			}
		}
	}
	else{
		if(n == 1) b = 0;
		else{
			for(int i = 0;i < t / 2 - 1;i++){
				if(a[i]!=a[t-i-1]){
					b = 1;
					break;
				}
			}
		}
	}
	if(b==0) cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;

}

