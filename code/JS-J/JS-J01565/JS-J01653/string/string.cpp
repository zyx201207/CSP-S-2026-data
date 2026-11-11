#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],ans,l,all;
char c[200005];
inline void s(long long y,long long x,char x1){
	int i=1;
	while(b[i]<x)i++;
	while(x<y){
		if(c[i]!=x1){
			ans+=min(b[i]-x,y-x);
		}
		x=b[i];
		i++;
	}
}
int main(){
	cin>>n;
	freopen("w","string.in",stdin);
	freopen("r","string.out",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		all+=a[i];
		cin>>c[i];
	}
	l=all/2+1;
	for(int i=1;1;i++){
		if(b[i]>l){
			s(all-b[i-1],l*2-b[i-1],c[i]);
			break;
		}
		s(all-b[i-1],all-b[i],c[i]);
	}
	cout<<ans;
}
