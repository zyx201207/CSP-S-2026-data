//T1 88
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],fl1=1,fl2=1,fl3=1,qhe[500100],phe[500100],cf[500100],pre[500100];
long long check(long long k){
	//cout<<k<<' ';
	long long sums=0x7f7f7f7f7f7f7f7f;
	
	for(int i=1;i<=n-k+1;i++){
		long long minn=0x7f7f7f7f7f7f7f7f,sum=0;
		//for(int j=i;j<=i+k-1;j++) minn=min(minn,qhe[j]);
		//for(int j=i;j<=i+k-1;j++) sum+=(qhe[j]-minn);
		sums=min(sums,pre[i+k-1]-pre[i-1]);
		//cout<<sums<<' ';
		//cout<<minn<<' ';
	}//
	sums--;
	//cout<<k<<'\n';
	return sums<=m;
}//a2+a3+a4+a5
//a1+^a5-a1
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)fl1=0;
		if((a[i]-a[i-1]!=a[2]-a[1]) && i!=1)fl2=0;
		if(a[i]>100)fl3=0;
	}
	if(fl1){
		int len=0;
		for(int i=0;i<=n-1;i++){
			m-=i;
			if(m<0) break;
			len++;
		}cout<<len;
	}else if(fl2){
		long long len=0,_m=m,o=a[n];
		for(int j=n;j>=1;j--){
			_m-=(o-a[j]);
			if(_m<0) break;
			len++;
		}cout<<len;
	}else{//2 3
		long long maxx=-0x7f7f7f7f7f7f7f7f,idx=1;
		sort(a+1,a+n+1);
			for(int i=1;i<=n;i++){
				cf[i]=abs(a[i]-a[i-1]);
				
				//maxx=max(a[i]-a[i-1],maxx);
				if(i<n)qhe[i]=a[n]-a[i];
			}//
			//cout<<idx-1<<'\n';
			//cout<<'\n';
			//sort(cf+1,cf+n+1);
		if(n<=5000){
			long long maxn=-1;
			for(int i=n;i>=1;i--){
				long long cnt=0,_m=m,o=a[i];
				for(int j=i;j>=1;j--){
					_m-=(o-a[j]);
					if(_m<0) break;
					cnt++;
					
				}maxn=max(maxn,cnt);
			}cout<<maxn;
		}else{
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+cf[i]*(i-1);
		//for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		//cout<<'\n';
		//for(int i=1;i<=n;i++) cout<<cf[i]<<' ';
		//cout<<'\n';
		//for(int i=1;i<=n;i++) cout<<pre[i]<<' ';
		//cout<<'\n';
		/*
		if(fl3 && n>5000){
			for(int i=1;i<=n;i++){
				
			}
		}*/
		long long maxn=-2147483648,l=1,r=n;
		while(l<r){
			long long mid=l+(r-l)/2;
			//cout<<mid<<'\n';
			if(check(mid)){
				maxn=mid;
				l=mid+1;
			}else r=mid;
		}cout<<maxn;
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

//15 2
//1 1 1 1 2 2 2 4 4 5 5 5 5 5 5
//0 0 0 0 1 0 0 02 00 01 00 00 00 00 00
//0 0 0 0 4 4 4 18 18 27 27 27 27 27 27
