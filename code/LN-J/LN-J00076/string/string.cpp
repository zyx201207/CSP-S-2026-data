#include<bits/stdc++.h>
using namespace std;
int a[200010],c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	if(n==1) cout << 0;
	long long t=0;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		t+=a[i];
	}
	string s="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long sum=0;
	if(t%2==0){
		long long m=t/2-1;
		for(int i=0,j=t;i<=m,j>=m+1;i++,j--){
			if(s[i]!=s[j]) sum++; 
		}
	}
	else{
		long long m=t/2;
		for(int i=0,j=t;i<=m,j>=m;i++,j--){
			if(s[i]!=s[j]) sum++;
		}
	}
	cout << sum;
	return 0;
}


