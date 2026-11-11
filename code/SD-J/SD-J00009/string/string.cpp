#include <bits/stdc++.h>
using namespace std;
string a;
long long x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,cntlen=0;
	cin >>n;
	for(int i =0;i<n;i++){
		cin >>x[i];
		/*cin >> a[cntlen];
		cntlen++;
		for(int j =1;j<=x[i];j++){
			a+=a[cntlen-1];
			cntlen++;
		}*/
		char sd;
		cin >>sd;
		a.insert(cntlen,x[i],sd);
		cntlen+=x[i];
	}
	for(int i=0;i<=a.size()/2-1;i++){
		if(a[i] != a[a.size()-1-i]) cnt++;
	}
	cout << cnt; 
	
	return 0;
}
