#include<bits/stdc++.h>
using namespace std;
const int MAX=200114;
int n,a[MAX];
char c[MAX];
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int f=1;
	int g=n;
	int i=1;
	while(i<=sum/2&&f<=g){
		int j=sum-i+1;
		if(a[f]<a[g]){
			if(c[f]!=c[g]){
				ans+=a[f];
			}
			a[g]-=a[f];
			i+=a[f];
			f++;
		}
		else if(a[f]>a[g]){
			if(c[f]!=c[g]){
				ans+=a[g];
			}
			a[f]-=a[g];
			i+=a[g];
			g--;
			
		}
		else if(a[f]==a[g]){
			if(c[f]!=c[g]){
				ans+=a[g];
			}
			i+=a[g];
			g--;
			f++;
			
		}
	}
	cout<<ans;
	return 0;
}
