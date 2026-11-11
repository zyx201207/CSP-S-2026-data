#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
long long s[N];
char p[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>p[i];
	}
	int r=n,l=1;
	long long ans=0;
	while(l<r){
		//cout<<ans<<endl;
		if(s[l]>s[r]){
			s[l]-=s[r];
			if(p[l]!=p[r]) 	ans+=s[r];
			r--;
		}else if(s[l]==s[r]){
			if(p[l]!=p[r]) 	ans+=s[r];
			r--;
			l++;
		}else{
			s[r]-=s[l];
			if(p[l]!=p[r]) 	ans+=s[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
