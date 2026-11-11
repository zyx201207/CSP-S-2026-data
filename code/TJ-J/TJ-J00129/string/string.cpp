#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	int f1=0;
	cin >> n;
	string b;
	int ans=0;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin >> a >> c;
		for(int j=0;j<a;j++){
			b+=c;
		}
	}
	int l=b.length();
	for(int i=1;i<l;i++){
		if(b[i]!=b[i-1]){
			f1+=1;
		}
	}
	int bet=l+1/2;
	if(f1!=0){
		cout << 2;
		for(int i=bet+1;i<l;i++){
			if(b[i]!=b[l+1-i]){
				ans++;
			}
		}
		cout << ans << endl;
	}
	else{
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
