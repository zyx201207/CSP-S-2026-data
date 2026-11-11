#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500050]={};
//int c[500050]={};
int zs[500050]={};
int fs[500050]={};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//a[i]=x+1e12;
		//a[i]+=1e12;
	}
	int mx=-1;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			int l=i;
			int r=j;
			int mid=(l+r)/2;
			int sum=0;
			//cout<<i<<" "<<j<<":"<<endl;
			for(int k=l;k<=mid;k++){
				sum+=(a[mid]-a[k]);
				//cout<<a[mid]-a[k]<<endl;
			}
			//cout<<endl;
			for(int k=mid;k<=r;k++){
				sum+=(a[k]-a[mid]);
				//cout<<a[k]-a[mid]<<endl;
			}
			//cout<<endl;
			if(sum<=m){
				mx=max(mx,r-l+1);	
			}
		}
	}
	cout<<mx<<endl;
	/*
	for(int i=1;i<=n;i++){
		zs[i]=zs[i-1]+(a[i]-a[1]);
		cout<<zs[i]<<endl;
	} 
	for(int i=n;i>=1;i--){
		fs[i]=fs[i+1]+(a[n]-a[i]);
		cout<<fs[i]<<endl;
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int mx=1;
	int ansl,ansr;
	while(l<=r){
		int mid=(l+r)/2;
		//int sum=zs[mid]-zs[l]+fs[r]-fs[mid];
		///cout<<sum<<endl;
		if(zs[r]-zs[l]<=m){
			if(r-l+1>mx){
				mx=r-l+1;
				ansl=l;
				ansr=r;
			}
			r--;	
		}else{
			l++;
		}
	}
	cout<<mx<<endl;
	cout<<a[ansl]<<" "<<a[ansr]<<" "<<endl; */
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

