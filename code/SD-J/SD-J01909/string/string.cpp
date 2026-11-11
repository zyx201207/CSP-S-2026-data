#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n+1],sum=0,m=0;
	char c[n+1];
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int t=0;
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i+1]){
			t=1;
		}
	}
	if(t==0)cout<<t;
		for(int i=1;i<=sum/2;i++){
			if(s[i]!=s[sum-i+1]){
				m++;
			}
		}
		cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
