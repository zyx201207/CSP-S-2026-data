#include<bits/stdc++.h>
using namespace std;
int const N=2*1e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n;
	cin>>n;
	int k=n;
	for(int i=1;i<=n;i++){
		int a1;
		char c1;
		cin>>a1>>c1;
		if(i!=1 && c1==c[i-1]){
			a[i-1]+=a1;
			k--;
		}
		else{
			a[i]=a1;
			c[i]=c1;
		}
	}
	long long sum=0;
	k/=2;
	for(int i=1;i<=k;i++){
		if(c[i]!=c[n+1-i]){
			if(a[i]>=a[n+1-i]){
				a[i]-=a[n+1-i];
				a[n+1-i]=0;
				sum+=a[i]-a[n+1-i];
			}else{
				a[n+1-i]-=a[i];
				a[i]=0;
				sum+=a[n+1-i]-a[i];
			} 
		}
		if(a[i]==0)n-=1;
		if(a[n+1-i]==0)n-=1;
		if(a[i]!=0)i--;
	}
	cout<<sum<<endl;
	return 0;
}
 
