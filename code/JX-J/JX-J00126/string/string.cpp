#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long  n=100,m=0,w,z,flag=0,mis=0,e,l,t;
	cin>>n;
	vector<char>a(n+1,0);
	vector<long long>b(n+1,0);
	for(long long i=1;i<=n;i++){
		long long q;
		scanf("%lld %c",&q,&a[i]);
		m+=q;
		b[i]=m;
	}
	w=(m+1)/2;
	for(long long i=1;i<=n;i++){
		if(i>0){
			if(a[i]!=a[i-1])flag=1;
		}	
		if(b[i]<w){
			z=i+1;
		}
		if(flag==1 and b[i]>=w)break;
	}
	if(flag==0){
		cout<<0;
	}else{
		mis += max(b[z]-b[z-1]-(b[z]-w),(b[z]-w)-b[z]+b[z-1]);
		

		l=z+1;
		t=z-1;
		e=b[l];
		b[l]-=b[l-1];
		
		b[t]-=b[t-1];
		b[t]-=b[z]-w;
		while(l<=n and t>=1){
			if(a[l]!=a[t]){
				mis+=min(b[l],b[t]);
			}
			if(b[l]>b[t]){
					b[l]-=b[t];
					t-=1;
					b[t]-=b[t-1];
				}else if(b[l]<b[t]){
					b[t]-=b[l];
					l+=1;
					m=b[l];
					b[l]-=e;
					e=m;
				}else{
					t-=1;
					b[t]-=b[t-1];
					l+=1;
					m=b[l];
					b[l]-=e;
					e=m;
				}
		}
	}
	cout<<mis;
	return 0;
}
