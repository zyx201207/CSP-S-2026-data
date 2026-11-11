#include<bits/stdc++.h>
using namespace std;
char c[200010];
int a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string s="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
//	cout<<s<<"\n";
	long long ans=0;
	if(c[1]!=c[n]){
		ans=min(a[1],a[n]);
	}
	int l=min(a[1],a[n]),r=s.size()-1-min(a[1],a[n]);
	while(l<=r){
		if(s[l]!=s[r]){
			s[r]=s[l];
			ans++;
//			printf("l=%d r=%d s[l]=%c s[r]=%c s:",l,r,s[l],s[r]);
//			cout<<s<<" "<<ans<<"\n";
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a

*/
