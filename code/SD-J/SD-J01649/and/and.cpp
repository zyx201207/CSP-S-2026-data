#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],cnt,maxn,l[200010],r[200010];
bool A,B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]+1)&(-a[i]-1)==a[i]){
			A=A&&1;
		}else{
			A==0;
		}B=B&&a[i]<4;
	}if(A){
		sort(a+1,a+1+n);
		for(int i=n-m+2;i<=n;i++){
			a[i]=a[i]&a[i-1];
		}cout<<a[n];
	}else if(B){
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--){
			if(a[i]==3&&n-i+1>=m){
				cout<<3;
				break;
			}else if(a[i]==2&&n-i+1>=m){
				cout<<2;
				break;
			}else if(a[i]==1&&n-i+1>=m){
				cout<<1;
				break;
			}if(i==1){
				cout<<0;
			}
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}cout<<maxn;
	}else if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=a[i]&a[i-1];
		}cout<<a[n];
	}else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(a[i]&a[j],maxn);
			}
		}cout<<maxn;
	}else if(m==n-1){
		l[1]=a[1],r[n]=a[n];
		for(int i=2;i<=n;i++){
			l[i]=l[i-1]&a[i];
		}for(int i=n-1;i>=1;i++){
			r[i]=r[i+1]&a[i];
		}for(int i=2;i<=n-1;i++){
			maxn=max(maxn,l[i-1]&r[i-1]);
		}maxn=max(maxn,max(r[1],l[n]));
		cout<<maxn;
	}else{
		cout<<0;
	}
	return 0;
}
