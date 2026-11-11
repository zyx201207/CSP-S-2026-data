#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],t[26],kn,ans;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		t[c[i]-'a']+=a[i];
		for(long long j=0;j<a[i];j++){
			s=s+c[i];
		}
	}
	for(int i=0;i<26;i++){
		if(t[i]>0){
			kn++;
		}
	}
	if(kn==2){
		int s1=0,s2=0;
		for(int i=0;i<26;i++){
			if(t[i]!=0){
				if(s1==0){
					s1=t[i];
				}
				else{
					s2=t[i];
				}
			}
			else{
				continue;
			}
		}
		ans=min(s1,s2);
		cout<<ans<<endl;
		return 0;
	}
	long long l=0,r=s.size()-1;
	while(l<r){
		if(s[l]==s[r]){
			l++;
			r--;
			continue;
		}
		if(t[s[l]-'a']<=t[s[r]-'a']){
			s[l]=s[r];
			ans++;
		}
		else{
			s[r]=s[l];
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans<<endl;
	return 0;
}
