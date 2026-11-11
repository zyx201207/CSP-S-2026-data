#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,step;
	cin >> n;
	string a[100];
	int num[100];
	for(int i = 0;i<=n-1;i++){
		cin >> num[i];
		cin >> a[i];
	}
	if(n == 1){
    	cout << 0;
    	return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
