#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	char a[2000005];
	long long len=1;
	for(int i=1;i<=n;i++){
		long long m;
		char k;
		cin>>m>>k;
		for(long long j=1;j<=m;j++){
			a[len]=k;
			len++;
		}
	}
	int l=1,r=len-1,ans=0;
	while(l<r){
		if(a[l]!=a[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
