#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	long long n,m,a[100000];
	long long l=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i+2<n;i++){
		int s1=a[0];
		for(int s2=1;s2<m;s2++){
			s1=s1^s[i+s2];
		}
		if(s1>l)l=s1;
	}
	cout<<s1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}