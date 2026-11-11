#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[2000009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,b,r,c,sum=0;
	cin>>c>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>r;
		for(int i=1;i<=b;i++){
			cin>>a[i];
		}
		if(b<4){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=b-3;i++){
			if(((a[i+2]-a[i])<=r)&&((a[i+3]-a[i])>r)&&((a[i+3]-a[i+1])<=r)){
				sum++; 
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
