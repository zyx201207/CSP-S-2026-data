#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long s=0;
	for(int i=30;i>=0;i--){
			long long c=0,t=s|(1<<i);
			for(int j=1;j<=n;j++){
				if((a[j]&t)==t){
						c++;
				}
			}
			if(c>=m){
				s=t;
			}
			
	}
	cout<<s;
	return 0;
}
