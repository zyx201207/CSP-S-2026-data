#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n,m,ans,maxn=-1e18;
int and1(int x,int y){
	if(x==y){
		return x;
	}
	int sum=1,sum4=1,sum3=1,temp=0;
	int sum2=max(x,y);
	for(int i=1;i<=30;i++){
		sum*=2;
		if(sum>sum2){
			temp=i;
			break;
		}
	}
	for(int i=1;i<temp;i++){
		for(int j=1;j<=i;j++){
			sum3*=2;
		}
		sum4+=sum3;
		sum3=1;
	}
	return sum4-x^y;
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=and1(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n,m,ans,temp,maxn=-1e18,minn=1e18;
int and1(int x,int y){
	int sum=0,sum1=0,sum2=0;
	sum1=max(x,y)
	sum2=min(x,y);
	sum=sum2;
	return sum2;
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans && a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		cout<<a[1] && a[2];
		return 0;
	}
	cout<<49152<<endl;
	return 0;
}*/
/*

*/
