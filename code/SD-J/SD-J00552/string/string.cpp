#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],ans,x=1;
char c[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s[x]=c[i];
			x++;
		}
	}
	long long m=x-1;
	for(long long i=1;i<=x-1;i++){
		if(s[i]!=s[m]){
			s[m]=s[i];
			ans++;
			m--;
		}
	}
	if(ans!=0) cout<<ans-1;
	else cout<<ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
