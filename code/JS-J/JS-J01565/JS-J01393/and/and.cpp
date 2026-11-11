#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int b[40];
int le[5];
signed f(int h,int num,int p){
	if(n-h+1<m-p){
		return 0;
	}
	if(p==m){
		return num;
	}
	return max(f(h+1,num&a[h],p+1),f(h+1,num,p));
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	int k=1;
	for(int i=1;i<=31;i++){
		b[i-1]=k;
		k*=2;
	}
	b[31]=k;
	k-=1;
	bool ea=1;
	bool p=1;
	bool less=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];

		maxn=max(maxn,a[i]);
		bool f=1;
		for(int j=0;j<=31;j++){
			if(b[j]-1==a[i]){
				
				f=0;
				break;
			}
		}
		if(f){
			ea=0;
		}
		if(a[i]!=i-1){
			p=0;
		}
		if(a[i]>=4){
			less=0;
		}
	}
	int h=a[1];
	for(int i=2;i<=n;i++){
		h&=a[i];
		
	}

	if(m==1){
		cout<<maxn;
	}
	else if(m==n){
		cout<<h;
	}
	else if(ea==0&&p==0&&less==0){
		cout<<f(1,k,0);
	}
	else if(ea==1){
		sort(a+1,a+n+1);
		
		for(int i=n;i>=n-m+1;i--){
			k&=a[i];
		}
		cout<<k;
	}
	else if(p==1){
		if(m<n/2){
			for(int i=n;i>=n-m+1;i--){
				k&=a[i];
			}
			cout<<k;
		}
		else{
			cout<<f(1,k,0);
		}
	}
	else if(less){
		for(int i=n;i>=1;i--){
			if(a[i]==3){
				le[1]++;
				le[2]++;
				le[3]++;
			}
			if(a[i]==2){
				le[2]++;
			}
			if(a[i]==1){
				le[1]++;
			}
	
		}
		
		if(le[3]>=m){
			cout<<3;
		}
		else if(le[2]>=m){
			cout<<2;
		}
		else if(le[1]>=m){
			cout<<1;
		}
		else {
			
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
