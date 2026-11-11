#include<bits/stdc++.h>
using namespace std;
int SS,T,n,k,i,x,y,m,s;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>SS>>T;
	while(T--){
		cin>>n>>k;
		for(i=1;i<n;i++)cin>>x>>y;
		m=(n-1)/2;m++;
		s=m/k;
		if(k==n)cout<<0<<"\n";
		else if(k>=m)cout<<1<<"\n";
		else cout<<(m+k-1)/k/2<<"\n";
	}
	return 0;
}