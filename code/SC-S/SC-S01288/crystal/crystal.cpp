#include<bits/stdc++.h> 
using namespace std;
long long a[500005],c[500005],b[500005],a1[500005],a2[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,a1s=0,flag,aa=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0){
			a1s++;
			a1[a1s]=0-a[i];
		}
	}
	if(n>5000){
		long long w=a[2]-a[1];
		long long sum=0;
		long long iii=0;
		while(1>0){
			iii++;
			sum+=iii*w;
			if(sum==m){
				cout<<iii+1;
				return 0;
			}
			if(sum>m){
				cout<<iii;
				return 0;
			}
		}
	} 
	sort(a1+1,a1+a1s+1);
	long long a2s=a1s;
	for(long long i=1;i<=n;i++){
		if(a[i]>=0){
			a2s++;
			a2[a2s]=a[i];
		}
	}
	int ss=0; 
	sort(a2+1,a2+a2s+1);
	for(long long i=a1s;i>=1;i--){
		ss++;
		a2[ss]=0-a1[i];
	}
	for(long long i=n;i>=1;i--){
		for(long long j=1;j<=i-1;j++){
			c[i]+=a2[i]-a2[j];
		}
		if(c[i]==m){
			ans++;
			b[ans]=i;
		}
	}
	sort(b+1,b+ans+1);
	if(ans!=0){
		cout<<b[ans];
	}else{
		for(int i=1;i<=n;i++){
			if(c[i]>m){
				cout<<i-1;
				return 0; 
			}
		}
	}
	return 0;
}