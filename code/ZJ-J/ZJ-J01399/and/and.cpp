#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,s[200005],x,l,v[200005],t[200005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}
	while(x){
		l++;
		x/=2;
	}
	x=pow(2,l);	
	for(int j=l;j>=0;j--){
		int c=0;
		for(int i=1;i<=n;i++){
			if(a[i]/x%2){
				c++;
				t[c]=a[i];
			}
		}
		if(c==m){
			break;
		}
		else if(c>m){
			for(int i=1;i<=c;i++){
				a[i]=t[i];
			}
			n=c;
		}
		x/=2;
	}
	ans=t[1];
	for(int i=2;i<=m;i++){
		ans=ans&t[i];
	}
	cout<<ans;
	return 0;
}
