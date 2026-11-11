#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char ch[200010];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l=0;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>ch[i];
		for(int j=0;j<a[i];j++){
			s+=ch;
		}
		l+=a[i];
	}
	string ss=s;
	reverse(ss.begin(),ss.end());
	long long ans=0;
	for(long long i=0;i<l/2;i++){
		if(s[i]!=ss[i]){
			ans++;
		}
	}
	cout<<ans;
	/*
	long long ans=0,pos=0,cnt=0;
	if(ss==s){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n/2;i++){
		if(s[i]!=ss[i]){
			ans+=min(a[i],a[n-i-1]);
		}
	}
	for(int i=0;i<n/2;i++){
		long long pos=i,x=max(a[i],a[n-i-1])-min(a[i],a[n-i-1);
		
		
		if(a[i]>a[n-i-1]){
			if(a[i+1]<a[n-i]){
				a[n-i-1]+=abs(a[i]-a[n-i-1]);
				a[n-i]-=abs(a[i]-a[n-i-1]);
			}
			else{
				a[i]-=abs(a[i]-a[n-i-1]);
				a[i+1]+=abs(a[i]-a[n-i-1]);
			}
		}
		else if(a[i]<a[n-i-1]){
			if(a[i+1]<a[n-i]){
				a[n-i-1]+=abs(a[i]-a[n-i-1]);
				a[n-i]-=abs(a[i]-a[n-i-1]);
			}
			else{
				a[i]-=abs(a[i]-a[n-i-1]);
				a[i+1]+=abs(a[i]-a[n-i-1]);
			}
		}
	}
	cout<<ans;*/
	return 0;
}
