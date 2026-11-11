#include <bits/stdc++.h>
using namespace std;
long long n,a[5000],b[5000],o=1,masx;//,sum;
//string m; 
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n);
b[0]=a[0];//cout<<b[0];
//sum=a[0];
m=abs(m);
while(m) {
	
	for(int i=o;i<n;i++){
		long long str=abs(a[i]-b[masx]);
//		if(m==0)break;
		if(masx<=n-1){
			cout<<n;
			return 0;
		}
		if(a[i]==b[masx]){
			masx++;
			break;
		}
		
		else if(a[i]>b[masx]&&m>=str*(masx+1)){
			
			m-=str*(masx+1);
			//cout<<m<<' ';
			masx++;
//			sum=a[i];
			b[masx]=a[i];
		}
		//cout<<masx<<endl;
	}
	
}
	cout<<masx+1;
return 0;
} 
