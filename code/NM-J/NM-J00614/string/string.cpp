#include<bits/stdc++.h>
using namespace std;
struct c{
	int a;
	char b; 
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,r=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
		r+=a[i].a;
	}
	string p;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].a;j++){
			p+=a[i].b;
		}
	}
	r--;
	int l=0,ans=0;
	while(l<=r){
		if(p[l]==p[r]){
			l++;
			r--;
			continue;
		}
		ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
