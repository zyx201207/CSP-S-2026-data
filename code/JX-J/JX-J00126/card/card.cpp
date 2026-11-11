#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n,m,w=0,flag=0;
	scanf("%lld %lld",&n,&m);
	vector<long long>a(n,0);
	vector<long long>b(m+1,0);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=0;i<n;i++){
		vector<long long>c(n,0);
		for(long long j=i;j<n;j++){
			if(c[a[j]]>=1){
				w=j;
			}
			c[a[j]]=j+1;
		}
		for(long long j=max(w,i);j<n;j++){
			b[a[j]]+=1;
		}
		w=0;
	}
	for(long long i=1;i<=m;i++){
		if(flag==0) flag=1;
		else cout<<" ";
		cout<<b[i];
	}
	return 0;
}
