#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200100;
int n,sum,k;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	if(n==1){
		cout<<0;
		return 0;
	} 
	if(n==2){
		if(c[1]==c[2])
			cout<<0;
			return 0;
		}	
	for(int i=n;i>=1;i--){
		k++;
		if(c[i]!=c[k]){
			if(a[i]==a[k]){
				c[i]=c[k];
				sum+=a[i]; 
			}
			else if(a[i]<a[k]){
				a[k]=a[i];
				a[k+1]=a[k+1]+a[k]-a[i];
				sum+=a[k];
			}
			else if(a[i]>a[k]){
				a[i]=a[k];
				a[i-1]+=a[i]-a[k];
				sum+=a[k];
			}
		}
		else if(c[i]==c[k]){
			if(a[i]!=a[k]){
				a[i]=a[k];
				a[i-1]-=a[k]-a[i];
				sum+=(a[k]-a[i])*2;
			}
		} 
	}
	cout<<sum;
	return 0;
} 
