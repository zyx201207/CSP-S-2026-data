#include<bits/stdc++.h>
using namespace std;
long long n,a[200020],l,r,cnt;
string c[200020],s,x;
int main(){
  	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> c[i];
		int sum= a[i];
		for(int j=0;j<a[i]%2;j++){
			 s+=c[i];
			 sum--;
		}
		sum/=2;
		x+=c[i];
		while(sum>1){
			x = x+x;
			sum/=2;
		}
		s+=x;
		x = ' ';
	}// ‰»Î 
	r = s.size()-1;
	for(int i=0;i<r/2;i++){
		if(s[i]!=s[r-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
} 
