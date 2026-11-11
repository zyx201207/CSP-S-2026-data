#include <bits/stdc++.h>
using namespace std;
string c[200010],s;
long long a[200010],t=0,n,t2=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		if(c[i]!=c[i+1]){
			t2++;
		}
	}
	if(t2==0){
		cout<<0;
		return 0; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	int t1=s.size();
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[t1]){
			t++;
			t1--;
		}
	}
	cout<<t;
	return 0;
}
