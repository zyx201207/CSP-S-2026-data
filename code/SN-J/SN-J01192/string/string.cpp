#include <bits/stdc++.h>
using namespace std;
//847-900
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	int n;
	cin >> n;
	//cout << n;
	long long a[n+5];
	char c[n+5];
	bool flag=true;
	cin >> a[0] >> c[0];
	for(int i=1;i<n;i++){
		cin >> a[i] >> c[i];
		if(c[i]!=c[0])flag=false;
	}
	if(flag){
		cout << 0;
		return 0;
	}
	string s1;
	long long i=0,j=0;
	while(j!=n){
		s1+=c[j];
		i++;
		//cout << 1;
		if(i==a[j]){
			i=0;
			j++;
		}
	} 
	long long ans=0;
	//cout << s1 << endl;
	for(int i=0;i<s1.length()/2;i++){
		//cout << s1[i] << ' ' << s1[n-i-1] << endl;
		if(s1[i]!=s1[s1.length()-i-1]){
			ans++;
			//cout << s1[i] << ' ' << s1[n-i-1] << " ans++" << endl;
		}
	}
	cout << ans;
}
