#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline long long read(){
	long long x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
ll n,m;
ll a[200020],ans,b[200020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		ans=a[1]&&a[2];
		for(int i=3;i<=n;i++){
			ans=ans&&a[i];
		}
		
	cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				b[i]=max(a[i]&a[j],b[i]);
			}
		}
		sort(b+1,b+n+1);
		ans=b[n];
		
	cout<<ans;
	}
	else if(m==n-1){
		if(a[2]-a[1]>a[n]-a[n-1]){
			ans=a[2];
			for(int i=3;i<=n;i++){
				ans=ans&&a[i];
			}
		}
		else {
			ans=a[1];
			for(int i=2;i<=n-1;i++){
				ans=ans&&a[i];
			}
		}
		
	cout<<ans;
	}
	else {
		cout<<a[n-m+1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

