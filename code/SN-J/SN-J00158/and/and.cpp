#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],maxx=-1,d[1005];
void dfs(long long x,long long y,long long z){
	if(y==m){
		maxx=max(maxx,z);
		return ;
	}
	if(x>=n){
		return ;
	}
	dfs(x+1,y+1,z&a[x]);
	dfs(x+1,y,z);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	d[0]=1;
	d[1]=2;
	d[2]=4;
	d[3]=8;
	d[4]=16;
	d[5]=32;
	d[6]=64;
	d[7]=128;
	d[8]=256;
	d[9]=512;
	d[10]=1024;
	d[11]=2048;
	d[12]=4096;
	d[13]=8192;
	d[14]=16384;
	d[15]=32768;
	d[16]=65536;
	d[17]=131072;
	d[18]=262144;
	d[19]=524288;
	d[20]=1048576;
	d[21]=2097152;
	d[22]=4194304;
	d[23]=8388608;
	d[24]=16777216;
	d[25]=33554432;
	d[26]=67108864;
	d[27]=134217728;
	d[28]=268435456;
	d[29]=536870912;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,33554431);
		cout<<maxx;
	}else if(n<=2000){
		if(m==1){
			for(int i=0;i<n;i++){
				maxx=max(maxx,a[i]);
			}
			cout<<maxx;
		}else if(m==2){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
			cout<<maxx;
		}else if(m==n){
			maxx=33554431;
			for(int i=0;i<n;i++){
				maxx=maxx&a[i];
			}
			cout<<maxx;
		}
	}else{
		if(m==n-1){
			for(int i=0;i<n;i++){
				long long s=33554431; 
				for(int j=0;j<n;j++){
					if(i!=j){
						s=s&a[j];
					}
				}
				maxx=max(maxx,s);
			}
			cout<<maxx;
		}else{
			bool w=1,e=1;
			for(int i=0;i<n;i++){
				bool w1=1,e1=1;
				for(int j=0;j<=29;j++){
					if(a[i]==d[j]){
						w1=0;
					}else if(a[i]==d[j]-1){
						e1=0;
					}
				}
				if(w1){
					w=0;
				}
				if(e1){
					e=0;
				}
			}
			if(e){
				sort(a,a+n);
				cout<<a[n-m];
			}else{
				maxx=536870911;
				for(int i=n-1;i>=n-m;i--){
					maxx=maxx&a[i];
				}
				cout<<maxx;
			}
		}
	}
	return 0;
}

