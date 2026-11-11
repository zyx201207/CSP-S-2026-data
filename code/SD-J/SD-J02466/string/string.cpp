#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		long long m;
		char k;
		cin>>m>>k;
		for(long long j=1;j<=m;j++){
			s+=k;
		}
	}
	long long i=0;
	long long j=s.length()-1;
	long long ans=0;
	while(i<=j){
		if(s[i]!=s[j]){
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

