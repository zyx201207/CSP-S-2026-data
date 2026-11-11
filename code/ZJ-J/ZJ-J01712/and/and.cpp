#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s[200005],cc,ans=-1e9;
int randint(int l,int r){
	return ((rand()<<16)+rand())%(r-l+1)+l;
}
int main(){
	srand(time(0));
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		cout<<a[1];
		return;
	}
	if(n<=200){
		for(int j=1;j<=n+1;j++) s[j]=a[j];
		for(int i=1;i<=1000000;i++){
			swap(s[randint(1,n)],s[randint(1,n)]);
			cc=s[n];
			for(int j=n-1;j>=n-m+1;j--) cc&=s[j];
			ans=max(ans,cc);
		}
	}
	else if(n<=10000){
		for(int j=1;j<=n;j++) s[j]=a[j];
		for(int i=1;i<=200000;i++){
			for(int j=1;j<=100;j++)
				swap(s[randint(1,n)],s[randint(1,n)]);
			cc=s[n];
			for(int j=n-1;j>=n-m+1;j--) cc&=s[j];
			ans=max(ans,cc);
		}
	}
	else{
		for(int j=1;j<=n;j++) s[j]=a[j];
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=100;j++)
				swap(s[randint(1,n)],s[randint(1,n)]);
			swap(s[randint(1,n)],s[randint(1,n)]);
			cc=s[n];
			for(int j=n-1;j>=n-m+1;j--) cc&=s[j];
			ans=max(ans,cc);
		}
	}
	cout<<ans;
}