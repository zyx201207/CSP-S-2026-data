#include<bits/stdc++.h>
//asd
using namespace std;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;cin>>n>>m;
	bool f=1,ff=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)f=0;
		bool df=0,pow=1;
		for(int j=1;j<=20;j++){
			pow*=2;
			if(pow>a[i])break;
			if(pow==a[i]){
				df=1;break;
			}
		}
		ff=df&&ff;
	}
	if(n<=20){//1-5
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n-m;i++){
			int sum=2147483647;
			for(int j=i;j<i+m;j++){
				sum=sum&a[j];
			}
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	else if(m==1){//6
		sort(a+1,a+1+n,cmp);
		cout<<a[1];
	}else if(m==n){//7
		int sum=2147483647;
		for(int i=1;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else if(n<=2000){//8-10
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n-1){//11-12
		sort(a+1,a+1+n,cmp);
		int sum=2147483647;
		for(int i=1;i<=m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else if(f){//14-15
		sort(a+1,a+1+n,cmp);
		int sum=2147483647;
		for(int i=1;i<=m;i++){
			sum=sum&a[i];
		}cout<<sum;
	}else if(ff){//13
		sort(a+1,a+1+n,cmp);
		int sum=2147483647;
		for(int i=1;i<=m;i++){
			sum=sum&a[i];
		}cout<<sum;
	}else{//16-20
		sort(a+1,a+1+n,cmp);
		int sum=2147483647;
		for(int i=1;i<=m;i++){
			sum=sum&a[i];
		}cout<<sum;
	}
	
	//tj-j00401
	//
	return 0;
} 
