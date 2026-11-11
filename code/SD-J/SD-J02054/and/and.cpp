#include<bits/stdc++.h>
using namespace std;
struct num_{
	int has1;
	long long num;
}a[200010];
bool cmp(num_ a,num_ b){
	return a.has1>b.has1||a.has1==b.has1&&a.num>b.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,u=0;
	cin>>n>>m;
	int z=n;
	while(z){
		u++;
		z/=2;
	}
	if(m==1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].num;
			mx=max(mx,a[i].num);
		}
		cout<<mx;
		return 0; 
	}
	else if(m==n){
		long long ans;
		for(int i=1;i<=n;i++){
			cin>>a[i].num;
			if(i==1) ans=a[i].num;
			else ans&=a[i].num;
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		long long mx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].num;
			long long l=a[i].num;
			for(int j=1;j<i;j++){
				mx=max(mx,l&a[j].num);
			}
		}
		cout<<mx;
		return 0;
	}	
	else if(pow(2,u-1)==n){
		for(int i=1;i<=n;i++){
			cin>>a[i].num;
		}
		int ans=n-1;
		for(int i=2;i<=m;i++){
			ans&=n-i;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		long long l=a[i].num;
		while(l){
			if(l%2) a[i].has1++;
			l/=2;
		}
	}
	sort(a+1,a+1+n,cmp);
	long long and_=a[1].num;
	for(int i=2;i<=m;i++){
		and_&=a[i].num;
	}
	cout<<and_;
	return 0;
}
