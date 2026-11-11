#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,m;
int a[200005];
int s[200005];
int maxn;
int h;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=false;//判断m是不是1 
	bool flag1=false;//判断m是不是n
	bool flag2=true;//特殊性质A 
	bool flag3=true;
	if(m==1){
		flag=true;
	}
	if(m==n){
		flag1=true;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i!=1){
			h=a[i];
		}else{
			h=h&a[i];
		}
		if(a[i]!=pow(2,i)-1){
			flag2=false;
		}
		if(a[i]<a[i-1]){
			flag3=false;
		}
		maxn=max(maxn,a[i]);
	}
	if(flag==true){
		cout<<maxn;
		return 0;
	}
	if(flag1==true){
		cout<<h;
		return 0;
	}
	if(flag2==true){
		cout<<n-m+1;
		return 0;
	}
	if(flag3==true){
		int p=a[n];
		for(int i=n-1;i>n-m;i--){
			p&=a[i];
		}
		cout<<p;
		return 0;
	}
	if(m==2){
		if(a[n]==a[n-1]){
			cout<<a[n];
			return 0;
		}else if(a[n-1]==a[n-2]){
			cout<<a[n-1];
			return 0;
		}else if(a[n-2]==a[n-3]){
			cout<<a[n-2];
			return 0;
		}
		cout<<max(a[n]&a[n-1],max(a[n-1]&a[n-2],a[n-2]&a[n-3]));
		return 0;
	}
	if(m==3){
		cout<<max((a[n]&a[n-1])&a[n-2],max((a[n-1]&a[n-2])&a[n-3],(a[n-2]&a[n-3])&a[n-4]));
		return 0;
	}
	if(m==n-1){
		int k=a[2];
		int l=a[1];
		for(int i=1;i<=n;i++){
			if(i!=1){
				k&=a[i];
			}
			if(i!=n){
				l&=a[i];
			}
		}
		cout<<max(l,k);
		return 0;
	}
	return 0;
}
