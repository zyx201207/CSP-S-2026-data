#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int c;
	cin>>n>>m;
	if(n%2==0){
		c=n/2;
	}else{
		c=n/2+1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c;j++){
			if(j!=c){
				if(a[c]<=a[j]){
					j++;
				}else{
					a[j]++;
					m--;
					if(a[c]==a[j]){
						cnt++;
					}
					if(m==0){
						continue;
					}
				}
			}
			else{
				j++;
			}
		}
	}
	cout<<cnt+1;
	return 0;
}