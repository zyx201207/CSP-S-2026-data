#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
long long n,m;
struct node{
	int d,z;
}a[N];
long long p[N];
long long cnt=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].d;
		a[i].z=1;
	}
	for(int b=1;b<=n;b++){
		for(int i=b;i<=n;i++){
			for(int j=b;j<=n;j++){
				if(a[i].d==a[j].d&&a[i].z==1&&a[j].z==1){
					a[i].z=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].z==1){
				cnt++;
			}
		}
		for(int i=b;i<=n;i++){
			a[i].z=1;
		}
		for(int i=b;i<=n;i++){
			for(int j=b;j<=n;j++){
				if(a[i].d==a[j].d&&a[i].z==1&&a[j].z==1){
					for(int k=i;k<j;k++){
						a[k].z=0;
					}
				}
			}
		}
		for(int i=b;i<=n;i++){
			if(a[i].z==1){
				p[a[i].d]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(p[i]!=0){
			cout<<p[i]<<" ";
		}
	}
	return 0;
}
