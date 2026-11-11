#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans;
char z;
string s,a,b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>z;
		for(int j=1;j<=m;j++){
			s+=z;
		}
		sum+=m;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(sum%2==0){
		for(int i=0;i<=sum/2-1;i++){
			a+=s[i];
			b+=s[sum/2+i];
		}
		for(int i=sum/2-1;i>=0;i--)
			c+=b[i];
		for(int i=0;i<=sum/2-1;i++){
			if(a[i]!=c[i]){
				ans++;
			}
		}
	}
	else if(sum%2==1){
		for(int i=0;i<=(sum-1)/2-1;i++){
			a+=s[i];
			b+=s[(sum+1)/2+i];
		}
		for(int i=(sum-1)/2-1;i>=0;i--)
			c+=b[i];
		for(int i=0;i<=(sum-1)/2-1;i++){
			if(a[i]!=c[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}