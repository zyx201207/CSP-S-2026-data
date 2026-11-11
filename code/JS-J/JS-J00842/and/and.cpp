#include<bits/stdc++.h>
using namespace std;
long long n,a[200003],m,longg,maxx=-1,t,r[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
bool flag[200003][30];
void totwo(long long x){
	for(int i=29;i>=0;i--){
		if(r[i]<=x){
			x-=r[i];
			flag[t][i]=true;
			if(i>longg){
				longg=i;
			}
		}else{
			flag[t][i]=false;
		}
	}return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		totwo(a[i]);
		t++;
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>maxx){
				maxx=a[i];
			}
		}cout<<maxx;
		return 0;
	}if(m==n){
		for(int i=0;i<n-1;i++){
			for(int f=0;f<=longg;f++){
				if(flag[i][f]==1&&flag[i+1][f]==1){
					flag[i+1][f]=true;
				}else{
					flag[i+1][f]=false;
				}
			}
		}long long y=0;
		for(int i=0;i<=longg;i++){
			if(flag[n-1][i]==1){
				y+=r[i];
			}
		}cout<<y;
		return 0;
	}if(2000<n&&n<=200002&&m!=n-1){
		sort(a,a+n);
		cout<<a[n-m];
		return 0;
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<=29;j++){
			if(flag[i][j]==true){
				cout<<1<<' ';
			}else{
				cout<<0<<' ';
			}
		}cout<<endl;
	}*/
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			//cout<<a[i]<<":"<<a[j]<<";";
			long long h=0;
			for(int f=0;f<=longg;f++){
				if(flag[i][f]==1&&flag[j][f]==1){
					h+=r[f];
					//cout<<h<<' ';
				}
			}
			if(h>maxx){
				maxx=h;
			}//cout<<endl;
		}
	}cout<<maxx;
	return 0;
}
