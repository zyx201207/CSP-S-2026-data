#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
bool as(int o){
	while(o%2==0&&o>0){
		o/=2;
	}
	if(o>1) return 0;
	else return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		int ma;
		cin>>ma;
		for(int i=2;i<=n;i++){
			int x;
			ma&=x;
		}
		cout<<ma;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		cout<<a[1];
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		if(as(a[1])){
			int ma=a[2];
			for(int i=3;i<=m;i++){
				ma&=a[i];
			}
			cout<<ma;
		}else{
			int ma=a[1];
			for(int i=2;i<=m-1;i++){
				ma&=a[i];
			}
			cout<<ma;
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		int ma,r=1;
		while(as(a[r])&&n-r+1>m) r++;
		ma=a[r];
		for(int i=r;i<=m;i++){
			ma&=a[i];
		}
		cout<<ma;
	}
	
	return 0;
}
