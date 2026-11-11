#include<bits/stdc++.h>
using namespace std;
int a[500100],a1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int w=0,o=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1] && n-i<=i){
			w=a[i];
			o=i;
			int sum1=0;
			for(int i=o-1;i>=1;i--){
				int t1=w-a[i];
				sum1+=t1;
				if(sum1<=m){
					a[i]=w;
				}else{
					int b2=1;
					for(int i=1;i<=n;i++){
						if(a[i]==a[i+1]){
							b2+=1;
						}else if(a[i]!=a[i+1] && a1<=b2){
							a1=b2;
							b2=1;
						}
					}
					cout<<a1;
					return 0;
				}
			}
			int b1=1;
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]){
					b1+=1;
				}
			}
			cout<<b1;
			return 0;
		}
	}
	int sum=0;
	for(int i=1;i<=n/2;i++){
		int t=a[n/2+1]-a[i];
		sum+=t;
		if(sum<=m){
			a[i]=a[n/2+1];
		}	
	}
	int b=1;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			b+=1;
		}
	}
	cout<<b;
	return 0;
} 
