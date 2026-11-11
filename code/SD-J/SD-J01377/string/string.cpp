#include<bits/stdc++.h>
using namespace std;
long long a[100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		m+=x;
		a[(int)y-'a']+=x;
		for(int j=1;j<=x;j++){
			s+=y; 
		}
	}
	long long sum=0;
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1]){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
