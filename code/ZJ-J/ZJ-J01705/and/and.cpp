#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=INT_MIN,minn=INT_MAX,ans1;
bool f=1;
bool check(int p){
	while(p!=1){
		if(p%2!=0) return 0;
		p/=2;
	}
	return 1;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!check(a[i]+1)) f=0;
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		ans1=a[1];
		for(int i=2;i<=n;i++){
			ans1=ans1&a[i];
		}
		cout<<ans1;
		return 0;
	}
	if(m==2){
		int maxnn=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int r=i&j;
				maxnn=max(maxnn,r);
			}
		}
		cout<<maxnn;
		return 0;
	}
	if(f){
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
		return 0;
	}
	if(maxn<4){
		int d[4];
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				d[0]++;
			}
			if(a[i]==1){
				d[1]++;
			}
			if(a[i]==2){
				d[2]++;
			}
			if(a[i]==3){
				d[3]++;
			}
		}
		if(d[3]>=m){
			cout<<"3";
		}else if(d[3]+d[2]>=m){
			cout<<"2";
		}else if(d[3]+d[1]>=m){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}
	return 0;
}
