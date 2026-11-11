#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long nl;
long long a[10000005];
long long l=0;

long long r=nl;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n>>nl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long k=0;
	if(n%2==0){
		k=n/2-1;
	}else{
		k=n/2;
	}
	long long suml=0;
	int cnt=0;
	for(int i=0;i<k;i++){
		 
		if(a[i]+l!=a[k]){
			 l=0;
			for(int j=0;j<nl;j++){
				if(a[i]+l==a[k]){
					a[i]=a[k];
					break;
				}else if(suml<=nl){
					l++;
					suml++;
					
				}else{
					break;
				}
			}
			
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[k]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
