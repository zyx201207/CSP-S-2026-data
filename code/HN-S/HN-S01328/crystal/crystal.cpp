#include<bits/stdc++.h>
using namespace std;
const long long N=1e7;
long long n,m,a[N],z,b,c,d,e,maxn;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin  >> a[i];
	}
	sort(a+1,a+1+n);
	for(int j=1;j<=n;j++){
		b=a[j];
		for(int i=1;i<=n;i++){
			if(a[i]<=b){
				z=b-a[i];
				if(z<=m){
					m=m-z;
					a[i]=b;
				}
			
				
			}
			z=0;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==b){
				d++;
				if(maxn<d){
					maxn=d;
				}
			}
		}
		b=0;
		d=0;
	}
	cout << maxn;
	return 0;
} 
