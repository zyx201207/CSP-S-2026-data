#include<bits/stdc++.h>
using namespace std;
char c[2005],c1,c2;
int n,ans=0,i1,i2;
long long a[2005],b[2005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=b[n]/2;i++){
		for(int j=1;j<=n;j++){
			if(b[j-1]<i&&b[j]>=i){
				i1 = j;
			}
			if(b[j-1]<b[n]-i+1&&b[j]>=b[n]-i+1){
				i2 = j;
			}
		}
		if(c[i1]!=c[i2]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}