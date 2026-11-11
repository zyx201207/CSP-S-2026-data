#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005];
bool vis[500005];
int sum;
int ans=1;
int main(){
	freopen("crystal.in",r,stdin);
	freopen("crystal.out",w,stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		
		//cout<<b[i]<<' ';
	}
	//sort(b+2/,b+n+1);
	int l=1,r=3,x=b[2],y=2;
	for(int i=2;i<=n;i++){
		if(b[i]<x&&vis[i]==0){
			x=b[i];
			y=i;
			l=i-1;
			r=i+1;
		}
	}ans=0;
	vis[y]=1;
	while(1){
		if(x>m){
			sum=max(sum,ans);
			break;
		}
		//cout<<l<<' '<<r<<endl;
		m-=x;
		b[y-1]+=x;
		b[y]-=x;
		//for(int i=1;i<=n;i++)cout<<b[i]<<' ';
		//cout<<l<<' '<<r<<endl;
		if(b[l]<b[r]&&l>=1){
			y=l;
			l-=1;
			x=b[y];
			
		}else if(b[l]==b[r]){
			if(l>=2&&r<n){
				if(min(b[l+1],b[l-1])>min(b[r+1],b[r-1])){
					y=l;
					l-=1;
					x=b[y];
				}else{
					l=y;
					y=r;
					r++;
					x=b[y];
				}
			}else if(l>=2){
				y=l;
				l-=1;
				x=b[y];
			}else{
				l=y;
				y=r;
				r++;
				x=b[y];
			}
		}
		else if(r<=n){
			l=y;
			y=r;
			r++;
			x=b[y];
		}
		
		//cout<<l<<' '<<r<<endl;
		//for(int i=1;i<=n;i++)cout<<b[i]<<' ';
		//cout<<endl;
	
	} 
	//for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	int cnt=1;
	for(int i=2;i<=n;i++){
		if(b[i]==0&&b[i]==b[i-1])
		 cnt++;
		 else{
		 sum=max(sum,cnt);
		 cnt=1;
		 }
		  
	}
	cout<<sum+1;
	
	return 0;
} 
