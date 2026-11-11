#include<bits/stdc++.h>
using namespace std;
const int  N=1e7*5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mx=-1,yigong=0;
	for(int i=1;i<=n;i++){
		long long lin=a[i];
		if(a[i]-a[i-1]>m){
			continue;
		}
		long long cut=m,sum=0;
		for(int j=i;j>=1;j--){
			if(lin-a[j]>cut){
				break;
			}
			cut-=lin-a[j];
			sum++;
		}
		
		mx=max(mx,sum);
	}
	cout<<mx;
	return 0;
} 
