#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long n,m,x[500001]={};
	cin>>n>>m;
	for(long long int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1);
	long long int o;
	o=x[n/2+1];
	while(1){
		long long int min=100000000000,minz;
		for(long long int i=1;i<=n;i++){
			if((abs(o-x[i])<min) && (o!=x[i])){
				min=o-x[i];
				minz=x[i];
				if(o-x[i]<=0){
					min=abs(o-x[i]);
					minz=o;
				}
			}
		}
		bool f=0;
		for(long long int i=1;i<=n;i++){
			if(x[i]==minz){
				x[i]++;
				m--;
				if(m==0){
					f=1;
					break;
				}
			}
		}
		if(f==1){
			break;
		}
	}
	long long int max=-500005;
	for(long long int i=1;i<=n;i++){
		long long int h=0;
		for(long long int j=1;j<=n;j++){
			if(x[j]==x[i]){
				h++;
			}
		}
		if(h>max){
			max=h;
		}
	}
	cout<<max;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
