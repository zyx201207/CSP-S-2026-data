#include <bits/stdc++.h>
using namespace std;
long long a,b,c[1000005],d,xy,ca[1000005],zj,max1=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(long long i=0;i<a;i++){
		cin>>c[i];
	}
	for(long long i=1;i<a;i++){
		if(c[i]>c[i-1]){
			ca[i]=c[i]-c[i-1];
		}
		else{
			ca[i]=c[i-1]-c[i];
		}
	}
	for(long long i=0;i<a;i++){
		d=1;
		xy=b;
		zj=0;
		for(long long j=i;j>0&&xy>=0;j--){
			zj+=ca[j];
			if(xy-zj>=0){
				d+=1;
				xy-=zj;
			}
			else{
				continue;
			}
		}
		if(d>max1){
			max1=d;
		}
	}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
