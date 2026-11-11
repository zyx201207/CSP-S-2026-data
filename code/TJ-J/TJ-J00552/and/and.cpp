#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
bool check(int x){
	for(int i=1;i<=n;i++){
		if(pow(2,i)==n) return true;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}
	else if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
			ma=max(ma,(a[i]&a[j]));
		}
		cout<<ma;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	else if(check(n)){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<m;i++){
			n/=2;
		}
		cout<<n;
	}
	else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
} 
