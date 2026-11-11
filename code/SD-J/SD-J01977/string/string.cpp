#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
char w[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0,m=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>w[i];
	}
	long long i=1;
	while(true){
		if(i>=n){
			break;
		}
		if(w[i]!=w[n]){
			ans+=min(a[i],a[n]);
			if(a[i]<a[n]){
				a[n]-=a[i];
				i++;
			}
			else{
				a[i]-=a[n];
				n--;
			}
		}
		else{
			if(a[i]!=a[n]){
				if(a[i]>a[n]){
					a[i]-=a[n];
					n--;
				}
				else{
					a[n]-=a[i];
					i++;
				}
			}
			else{
				i++;
				n--;
			}
		}
	}
	cout<<ans;
	return 0;
}
