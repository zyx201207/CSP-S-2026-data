#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans,sum=0,p=0,oo;
char c[200005];
string s,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1]>>c[1];
	for(int j=sum;j<a[1]+sum;j++){
		s[j]=c[1];
	}
	sum+=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[1]) ans++;
		for(int j=sum;j<a[i]+sum;j++){
			s[j]=c[i];
		}
		sum+=a[i];
	}
	if(ans==n-1) cout<<0;
	else{
		if(sum%2!=0){
			for(int i=sum-1;i>=(sum+1)/2;i--){
				if(s[p]!=s[i]) oo++;
				p++;
			} 
			cout<<oo;
		}else if(sum%2==0){
			for(int i=sum-1;i>=sum/2+1;i--){
				if(s[p]!=s[i]) oo++;
				p++;
			} 
			if(s[sum/2-1]==s[sum/2]) cout<<oo;
			else cout<<oo+1;
		}
	}
	return 0;
}

