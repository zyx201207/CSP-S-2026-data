#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,c2,s1,s2;
	long long a[5];
	cin >> c1 >> s1 >> c2 >> s2;
	char i=s1,j=s2;
	i/=100;
	j/=100;
	if(c1==c2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	int k=(int)s1/100;
	int t=(int)s2/100;
	if(k==t) {			
		cout << "1";
	} else {		
		cout << "0";
	}
	if(a[i]&&a[j]<a[3]||a[i]&&a[j]>=a[3]){		
		cout << "1";		
	}else{
		cout << "0";
	}
	if(a[i]-a[j]==1){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}