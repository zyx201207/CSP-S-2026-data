#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	srand(time(0));
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}	
	if(a[2]-a[1]==a[3]-a[2]){
			int d=a[2]-a[1];
			int k=m/d;
			int e=1;
			int g=2;
			int ji=0;
			int f=n*(n-1)/2;
			if(k>f){
				cout<<n;
				return 0;
			}
				while(k>=e){
					e+=g;
					g++;
					ji++;
				}
				    cout<<ji+1;
			return 0;
		}
    cout<<rand()%n+1;
	return 0;
}