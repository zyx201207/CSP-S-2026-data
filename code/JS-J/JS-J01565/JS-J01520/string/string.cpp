#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	string s="";
	for(int i=0;i<n;i++){
		char c;
		cin>>a[i]>>c;
		s+=c;
	}
	int cur=n-1;
	long long ans=0;
	for(int i=0;i<n;i++){
		if(i>=cur)break;
		while(a[cur]<a[i]){
			a[i]-=a[cur];
			if(s[i]!=s[cur])ans+=a[cur];
			cur--;
		}
		if(s[i]!=s[cur])ans+=a[i];
		a[cur]-=a[i];
	}
	cout<<ans;
	return 0;
}
