#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[1005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=1;i<=sum;i++){
		if(s[i]!=s[sum-i]){
			ans++;
		}	
	}
	cout<<ans-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
