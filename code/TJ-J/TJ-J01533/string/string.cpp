#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];
long long sum=0,ans=0;
string s,si1,si;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(sum%2==1){
		sum/=2;
		for(int i=0;i<sum;i++){
			si1+=s[i];
		}
		for(int i=sum-1;i>=0;i--){
			si+=si1[i];
		}
		for(int i=sum+1;i<s.size();i++){
			if(si[i-sum-1]!=s[i]) ans++;
		}
	}else if(sum%2==0){
		sum/=2;
		for(int i=0;i<sum;i++){
			si1+=s[i];
		}
		for(int i=sum-1;i>=0;i--){
			si+=si1[i];
		}
		for(int i=sum;i<s.size();i++){
			if(si[i-sum]!=s[i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
