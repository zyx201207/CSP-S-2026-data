#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200030],b[200030],h,ans=LLONG_MIN;
void havk(long long f,long long g){
	if(g==0){
		ans=max(ans,h);
		return;
	}
	for(int i=0;i<n;i++){
		if(a[i]==-1){
			continue;
		}
		long long o=h,u=a[i];
		h=h&a[i];
		a[i]=-1;
		havk(i,g-1);
		h=o;
		a[i]=u;
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	for(int i=0;i<n;i++){
		h=a[i];
		long long zx=a[i];
		a[i]=-1;
		havk(i,m-1);
		a[i]=zx;
	}
	cout<<ans;
} 
