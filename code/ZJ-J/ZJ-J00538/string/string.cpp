#include<bits/stdc++.h>
//#define int long long
using namespace std;
long long n,ans=0;
long long s[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
	}
	int j=n,i=1;
	while(i<=j){
		if(c[i]==c[j]){
			if(s[i]>s[j]){
				s[i]-=s[j];
				j--;
			}
			else{
				s[j]-=s[i];
				i++;
			}
		}
		else{
			if(s[i]>s[j]){
				s[i]-=s[j];
				ans+=s[j];
				j--;
			}
			else{
				s[j]-=s[i];
				ans+=s[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}