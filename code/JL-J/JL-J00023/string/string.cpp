#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	string a,b;
	int l = 0;
	for (int i = 0;i <n;i ++){
		int m;
		char n;
		cin>>m>>n;
		l += m;
		string c;
		for (int j = 0;j <  m;j++){
			c += n;
		}
		a +=c;
		}
	for (int i = l;i >= 0;i--){
		b += a[i];
	}
	long long count = 0;
	for (int i = 0;i <= l;i++){
		if (a[i] != b[i]){
			 count++;
		} 
	}
	
	if (count  == 2) cout<<0;
	else if (count % 2 != 0) cout<<count/2 +1;
	else cout<<count/2;
	return 0;
		
	}
