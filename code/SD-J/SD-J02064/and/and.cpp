#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans=0;
const int N=2e5+1;
int a[N];
int cf(int o,int p){
	int sum=1;
	for(int i=1;i<=p;i++){
		sum*=o;
	}
	return sum;
}
int f(int x,int y){
	int q[N],p[N];
	int kq=0,kp=0,cnt=0;
	if(x==y) return x;
	while(x!=0){
		kq++;
		q[kq]=x%2;
		x/=2;
	}
	while(y!=0){
		kp++; 
		p[kp]=y%2;
		y/=2;
	}
	for(int i=1;i<=max(kq,kp);i++){
		if(q[i]==p[i]) cnt+=cf(2,i-1);
	}
	return cnt;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++) cin>>a[i];	
		for(int i=1;i<n;i++){
			ans=max(ans,a[i]);
		}
	}else{
		if(m==n){
			for(int i=1;i<=n;i++) cin>>a[i];	
			for(int i=2;i<n;i++){
				a[i]=f(a[i-1],a[i]);
				cout<<a[n];
			}
		}else{
			if(m==2){
				for(int i=1;i<=n;i++) cin>>a[i];	
				for(int i=1;i<n;i++){
					for(int j=i+1;j<=n;j++){
						ans=max(f(a[i],a[j]),ans);
					}
				}
			cout<<ans;
			}else{
				cout<<0;
			}
		}
	}
	return 0;
}

