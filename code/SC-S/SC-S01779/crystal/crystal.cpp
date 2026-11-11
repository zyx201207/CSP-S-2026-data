#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
const int N=500005;
int a[N];
long long x=0;                 //相差
long long y=0;
long long z=1;                 //水晶数 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(m>0){
		x=a[i+1]-a[i];
		a[i]=a[i+1];
		y=i+1;
		z++;
		m-=(x*(i+1));
		if(m<0){
		z--;	
		}	
		}
		else{
			break;
		}
		} 
		for(int i=y+1;i<=n;i++){
			if(a[i]==a[y]){
				z++;
			}
		}
		cout<<z;
	return 0;
}