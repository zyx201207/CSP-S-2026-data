#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,g,c,d,cnt;
char z; 
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g>>z;
		c = g;
		for(int i=d;i<c+d;i++){
			s = s+z;
		}
		d = c;
	}
	int j = s.size()-1;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[j]){
			s[i] = s[j];
			j--;
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
