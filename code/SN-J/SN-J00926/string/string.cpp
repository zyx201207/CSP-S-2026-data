#include<bits/stdc++.h>
using namespace std;
int main(){
	
	string a,b;
	long long n,l,len=0,m,ans=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>b;
		len+=l;
		for(int j=1;j<=l;j++){
			
			a+=b;
		}
	}
	m=len/2;
	if(n%2==0){
		for(int i=m;i<=len-1;i++){
			if(a[i]!=a[len-1-i])ans++;
		}
	}
	else{
		for(int i=m+1;i<=len-1;i++){
			if(a[i]!=a[len-1-i])ans++;
		}
	}
	cout<<ans;
	return 0;
}
