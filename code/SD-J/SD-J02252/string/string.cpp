#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,sum=0,cm=0;
	char c;
	string s="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s[j+sum]=c;
		}sum+=a;
	}
	
	for(long long i=1;i<=sum/2;i++){
		if(s[i]!=s[sum-i+1]){
			cm++;
		}
	}
	cout<<cm;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
