//刘曌珩  SN-J00817  西安市含光中学 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long ans,sum,t,x;
bool cmp(int w,int e){
	return w>e;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(a[i],ans);
	}
	sum=a[1];
	for(int i=2;i<=n;i++){
		sum=sum&a[i];
		if(a[i-1]!=a[i]) x=1;
	}
	if(m==1){
		cout<<ans;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				t=max(t,a[i]&a[j]);
			}
		}
		cout<<t;
		return 0;
	}
	if(x==0){
		cout<<a[1];
		return 0;
	}
	if(n<=20){
		sort(a+1,a+n+1,cmp);
		t=a[1];
		for(int i=2;i<=m;i++){
			t=t&a[i];
		}
		cout<<t;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
