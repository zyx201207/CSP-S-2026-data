#include<bits/stdc++.h>
using namespace std;
int as[100000000],as1[100000000],v[100000000],a[100000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,v,w,t;
	int c,d,p;

	long long n;
	long long sb=0;
	long long k=0;
	long long cnt=0;
	cin>>c>>n>>m>>d>>p;
	char as1[n];
	for(long long i=0;i<n;i++){
		cin>>as[i]>>as1[i];
		sb=sb+as[i];
	}
	for(int i=0;i<=n/2;i++){
		if(!(as1[i]==as1[n-i-1])){
			if(as[i]<as[n-i-1]){
				for(int u=0;u<i+1;u++){
					as[n-i-1+u+1]=as[n-i-1+u];
					as1[n-i-1+u+1]=as1[n-i-1+u];
				}
				as[n-i-1]=as[n-i-1]-as[i];
				n++;
				cnt+=1;
				cnt=cnt+as[i];
			}
			if(as[i]>as[n-i-1]){
					for(int u=i;u<n+1;u++){
					as[u+1]=as[u];
					as1[u+1]=as1[u];
					
				}
				n++;
				cnt=cnt+as[n-i-1];
			}
			if(as[i]==as[n-i-1]){
				cnt=cnt+as[n-i-1];
			}

		}
	}
	
	
	cout<<cnt;
	return 0;
} 
