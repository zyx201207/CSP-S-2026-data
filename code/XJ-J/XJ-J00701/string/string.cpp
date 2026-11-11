#include <bits/stdc++.h> 
using namespace std;
#define int long long
int a[200005]={0};
char b[200005]={'0'};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		a[i]=x;
		b[i]=y;
		if(b[i]==b[i-1]){
			n--;
			i--;
			a[i-1]+=a[i];
		}
	}if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=ceil(n/2.0);++i){
		if(a[i]==a[n-i+1]){
			if(b[i]==b[n-i+1]){
				continue;
			}else{
				sum+=a[i];
			}
		}
		else{
			if(b[i]==b[n-i+1]){
				sum+=abs(a[i]-a[n-1+1]);
			}else{
				sum+=max(a[i],a[n-i+1]);
			}
		}
	}cout<<sum;
}
