#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
long long n,m,a[200010],i,maxa,s,e,r,q[200010],w[200010];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
	}else if(m==2){
		for(i=1;i<n;i++){
			if(a[i]==a[i+1]){
				maxa=a[i];
			}
		}		
		e=1;
		while(a[1]>0){
			if(a[1]%2==0){
				q[e]=0;
			}else{
				q[e]=1;
			}
			e++;
			a[1]/=2;
		}
		e=1;
		while(a[2]>0){
			if(a[2]%2==0){
				w[e]=0;
			}else{
				w[e]=1;
			}
			e++;
			a[2]/=2;
		}
		for(i=1;i<=e;i++){
			if(q[i]==1&&w[i]==1){
				s=s*2+1;
			}else{
				s*=2;
			}
		}
		cout<<max(s,maxa);
	}else if(m==n){		
		for(i=2;i<=n;i++){
			e=1;
			while(a[i]>0){
				if(a[i]%2==0){
					q[e]=0;
				}else{
					q[e]=1;
				}
				e++;
				a[i]/=2;
			}
			for(i=1;i<=e;i++){
				if(q[i]==1&&w[i]==1){
					s=s*2+1;
				}else{
					s*=2;
				}
			}			
		}
		
	}
	return 0;
}