//高嘉祺 SN-S00375 陕西省西安中学

#include<bits/stdc++.h>
using namespace std;
const long long INF = 1E12+1;
long long n,m;
long long num[500005];

	long long h=0;
bool check(long long d){
	long long k=0;
	h=0;
	for(int i=n;i>=1;i--){

		if(num[i]<=d){

			k = k + (d-num[i]);
			h++;
		}
		if(k>m) return 0;
	}
	return 1;
	
}


int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	long long mi=INF;
	
	for(int i=1;i<=n;i++){
		cin>>num[i];
		mi=min(mi,num[i]);
	}
	
	sort(num+1,num+1+n);
	
	
	if(m>1e8){
		
		for(int i=1;i<=n;i++){
			long long o=i*(num[1]+num[i])/2;
			if(o-num[i]>=m) {
				cout<<i-1;
				return 0;
			}
		}
	}
	
	
	
	
	
	
	long long l=mi-1,r=INF;
	
	while(l<r){
		long long mid=l+((r-l+1)/2);
		
		if(check(mid)){
			l = mid;
		}
		else r = mid-1;
		
	}
//	long long st=l;
//	long long ans=0;
//	for(int i=1;i<=n;i++){
//		if(num[i]<=l) ans++;
//	}
	cout<<h;



	return 0;
} 
