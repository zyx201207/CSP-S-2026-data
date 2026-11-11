#include<bits/stdc++.h>
using namespace std;
char s[200005];
long long s2[200005],n;
long long ans,tot;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>s2[i]>>s[i];
		tot+=s2[i];
	}
	for(long long i=1;i<=tot/2;i++){
		long long i2=i;
		char a,b;
		for(long long j=1;j<=n;j++){
			if(i2-s2[j]<=0){
				a=s[j];
				break;
			}
			i2-=s2[j];
		}
		long long i3=tot-i+1;
		for(long long j=1;j<=n;j++){
			if(i3-s2[j]<=0){
				b=s[j];
				break;
			}
			i3-=s2[j];
		}		
		if(a!=b){
			ans++;
		}
	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
