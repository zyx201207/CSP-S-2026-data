#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	long long n,m,cnt=0;
	cin>>n>>m;
	long long a[n+1]={0},b[n+1]={0};
	cin>>a[0];
	long long mi=a[0];
	long long mx=a[0];
	for(long long i=1;i<n;i++){
		cin>>a[i];
		if(i>0){
			mi=min(mi,a[i]);//最大 
			mx=max(mx,a[i]);//最小 
		}
	}
	
	long long cnt1[mx-mi]={0};
	
	long long j=mi;
	for(long long g=0;g<mx-mi;g++){ 
		cnt=0;
		for(long long i=0;i<n;i++){
			if((a[i]-j)>0){
				b[i]=999999999;
				break;
			}else{
				b[i]=abs(a[i]-j);
			}
			
		}

		sort(b,b+n);

		
		for(long long k=0;k<n;k++){		
			if((cnt+b[k])>m){
				break;
			}
			cnt+=b[k];
			cnt1[j-mi]++;
		}
		j++;
	}
	long long d=cnt1[0];
	for(long long i=1;i<mx-mi;i++){
		d=max(cnt1[i],d);//求最多水晶数 
	}
	cout<<d;
	return 0;
}
