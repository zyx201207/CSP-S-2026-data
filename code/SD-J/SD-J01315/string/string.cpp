#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],sum=0;
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1,j=n;i!=j;){
		if(b[i]!=b[j]){
			if(a[i]>=a[j]){
				a[i]-=a[j];
				sum+=a[j];
				j--;
			}
			else{
				a[j]-=a[i];
				sum+=a[i];
				i++;
			}
		}
		else{
			if(a[i]>=a[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}














