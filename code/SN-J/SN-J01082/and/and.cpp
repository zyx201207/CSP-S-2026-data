#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	int x1=0,y1=0;
	int x2=x,y2=y;
	while(x2>1){
		if(x2%2==1) x1++;
		x2/=2;
	}
	while(y2>1){
		if(y2%2==1) y1++;
		y2/=2;
	}
	if(x!=y) return x1>y1;
	else return x>y;
}
int main(){
	freopen("and.in" ,"r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[200010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max=0;
	if(n<=20){
		if(m==1){
			for(int i=1;i<=n;i++){
				if(a[i]>max) max=a[i];
			}
			cout<<max;
		}
		else if(n==m){
			int num=a[1];
			for(int i=2;i<=n;i++){
				num=num&a[i];
			}
			cout<<num;
		}
		else if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int num=a[i]&a[j];
					if(num>max) max=num;
				}
			}
			cout<<max;
		}
		else if(m==n-1){
			int num=a[2];
			for(int i=3;i<=n;i++){
				num=num&a[i];
			}
			max=num;
			for(int i=2;i<=n;i++){
				num=a[1];
				for(int j=2;i<=n;j++){
					if(j!=i) num=num&a[j];
				}
				if(num>max) max=num;
			}
			cout<<max;
		}
		else{
			sort(a+1,a+n+1,cmp);
			int num=a[1];
			for(int i=2;i<=m;i++){
				num=num&a[i];
			}
			cout<<num;
		}
	}
	else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				if(a[i]>max) max=a[i];
			}
			cout<<max;
		}
		else if(n==m){
			int num=a[1];
			for(int i=2;i<=n;i++){
				num=num&a[i];
			}
			cout<<num;
		}
		else if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int num=a[i]&a[j];
					if(num>max) max=num;
				}
			}
			cout<<max;
		}
	}
	else{
		if(m==n-1){
			int num=a[2];
			for(int i=3;i<=n;i++){
				num=num&a[i];
			}
			max=num;
			for(int i=2;i<=n;i++){
				num=a[1];
				for(int j=2;i<=n;j++){
					if(j!=i) num=num&a[j];
				}
				if(num>max) max=num;
			}
			cout<<max;
		}
		else{
			sort(a+1,a+n+1,cmp);
			int num=a[1];
			for(int i=2;i<=m;i++){
				num=num&a[i];
			}
			cout<<num;
		}
		
	}
	return 0;
}
