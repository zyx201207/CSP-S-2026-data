#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>d;
	while(d!=0){
		d--;
		long long sl,bc,s=0;
		scanf("%lld%lld",&sl,&bc);
		for(int i=1;i<=sl;i++){
			scanf("%lld",&a[i]);
		}
		if(bc!=2){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<sl;i++){
			if(a[i]+3==a[i+1]+2 and a[i]+3==a[i+2]+1 and a[i]+3==a[i+3]){
				s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}