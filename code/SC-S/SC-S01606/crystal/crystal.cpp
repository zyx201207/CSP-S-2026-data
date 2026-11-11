#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
long long m,s,k,w=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	k=m;
	for(long long i=1;i<=n;i++){
		if(k<=0)	break;
		for(long long j=1;j<i;j++){
			if(k<=0)	break;
			if(k>=a[i]-a[j]){
				int t=k;
				k-=a[i]-a[j];
				t=t-k;
				a[j]+=t;
			}
		}
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			w++;
		}if(a[i]>a[i-1]){
			s=max(s,w);
			w=1;
		}
	}cout<<s;
	return 0;
} 