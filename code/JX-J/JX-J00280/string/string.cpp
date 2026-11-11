#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);


	long long n;
	long long m;
	string s;
	char a[100000];
	long long ans;
	
	
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>m;
		cin>>a;
		for(int j=0; j<m; j++){
			s=s+a;
		}
	}
	int aaa=s.size();
	string a2,a3;
	for(int i=0; i<aaa/2-1; i++){
		a2=a2+s[i];
	}
	for(int i=aaa/2; i<aaa; i++){
		a3=a3+s[i];
	}
	for(int i=0; i<aaa/2; i++){
		if(a2[i]!=a3[i]){
			ans++;
		}
	}
	
	cout<<ans;
	

	return 0;
}
