#include<bits/stdc++.h>
using namespace std;
long long n,a,len,ans;
char c,b[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			b[j+len]=c;
		}
		len+=a;
	}
	for(long long i=1;i<=len/2;i++){
		if(b[i]!=b[len+1-i])ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

