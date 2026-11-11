#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10; 
int n;
long long a[N],m,k=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>a[i]) {
				k=j-1;
				break;
			}if(j==n&&a[j]<=a[i]){
				k=n;
			}
		}
		for(int j=1;j<=k;j++){
			if(m==0){
				cout<<k;
				return 0;
			}
			a[j]++;
			m--;
			
		}
		
	}
	
	return 0;
}