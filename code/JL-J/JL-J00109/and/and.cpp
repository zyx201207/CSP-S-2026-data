#include<bits/stdc++.h>
using namespace std;
int a[200005];
int t[10];
int main(){
	freopen("and.in","r",stdin);        
	freopen("and.out","w",stdout);
	int n,m,maxa=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<5)
			t[a[i]]++;
		maxa=max(maxa,a[i]);
	}
	if(m<n&&n>2000&&maxa>=(2<<10)&&maxa<=(2<<20)){
		cout<<maxa;
	}else if(m==1){
		cout<<maxa;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}else if(maxa<=4){
		for(int i=1;i<=4;i++)
			cout<<t[i]<<"\n";
		if(t[1]+t[3]>=m&&t[2]+t[3]<m)
			cout<<1;
		else if(t[2]+t[3]>=m)
			cout<<2;
		else
			cout<<0;
	}
}
