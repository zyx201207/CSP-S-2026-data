#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n;	
long long len=0;
long long a[200010];
char b[200010];
long long gcd(int x,int y){
	if(y==0)return x;
	else gcd(y,x%y);
}
long long check(string s1){
	long long l=1,r=len;
	long long ans=0;
	if(len%2==1){
		for(int i=0,j=len-1;i<=len/2-1;i++,j--){
			if(s1[i]!=s1[j])ans++;
		}
		return ans;
	}
	else{
		for(int i=0,j=len-1;i<=len/2-1;i++,j--){
			if(s1[i]!=s1[j])ans++;
		}
		return ans;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string sta;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	long long mod=a[1];
	len=a[1];
	for(int i=2;i<=n;i++){
		mod=gcd(mod,a[i]);
		len+=a[i];
	}
	len/=mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i]/mod;j++){
			sta+=b[i];
		}
	}
	long long res=check(sta)*mod;
	printf("%lld",res);
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
