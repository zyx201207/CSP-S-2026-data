#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200009];
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
	}
	else if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			long long c=a[1];
			if(i==1){
				c=a[2];
			}
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				c&=a[j];
			}
			ans=max(ans,c);
		}
	}
	else{
		int c1=0,c2=0,c3=0,c4=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)	c1++;
			if(a[i]==2)	c2++;
			if(a[i]==3)	c3++;
			if(a[i]==4)	c4++;
		}
		if(c4>=m)	ans=4;
		else if(c3>=m)	ans=3;
		else if(c3+c2>=m)	ans=2;
		else if(c3+c1>=m)	ans=1;
		else	ans=0;
	}
	cout<<ans<<"\n";
	return 0;
}
