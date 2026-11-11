#include<bits/stdc++.h>
using namespace std;
int n,c,t,s;
long long d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	for(int i=1;i<=t;i++){
		s=0;
		for(int j=1;j<n;j++){
			long long x=0;
			bool f=1;
			for(int k=j;k<n;k++){
				if(a[k+1]-a[k]<=d){
					x++;
				}else{
				    f=0;
					break;
				}
			}if(f && x==0)  x=(n-j+1)*(n-j)/2;
			if(x%d!=0)	s++;
		}
		cout<<s<<endl;
	}
	return 0;
}
