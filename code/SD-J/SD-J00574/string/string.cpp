#include <bits/stdc++.h>
using namespace std;
long long n,ans,mid;
long long x;
char c; 
string s;
void f(){
	long long i=0,j=s.size()-1;
	for (i<mid;j>=mid;i++,j--){
		if (s[i]==s[j]) continue;
		else ans++;
	}
	cout << ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while (n--){
		cin >> x >> c;
		for (int i=1;i<=x;i++){
			s+=c;
		}
	}
	if (s.size()%2==0){
		mid=s.size()/2;
	}else mid=s.size()/2+1;
	f();
} 
