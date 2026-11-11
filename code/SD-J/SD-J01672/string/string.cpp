#include <bits/stdc++.h>
using namespace std;
long long n;
long long r;
string x,s1;
long long len;
string s2,s3;
long long key;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> r >> x;
		len+=r;
		for(int j = 1;j<=r;j++){
			s1+=x;
		}
	}
	long long maxkey = 1000000000000;
	for(int i = 0;i<=len;i++){
		long long key = 0;
		string s2;
		string s3;
		for(int j = 0;j<=i;j++){
			s2+=s1[j];
		}
		for(int j = len-1;j>=i+1;j--){
			s3+=s1[j];
		}
		int i1 = len-i;
		for(int j = 0;j<=max(i,i1);j++){
			if(s2[j]!=s3[j]){
				key++;
			}
		}
		cout << key << " ";
		cout << s2 << endl;
		cout << s3 << endl;
		maxkey = min(maxkey,key);
	}
	cout << maxkey;
	return 0;
}
