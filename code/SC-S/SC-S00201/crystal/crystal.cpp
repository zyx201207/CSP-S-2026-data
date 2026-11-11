#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long cf[500005];
long long cfs[5005][5005]; //cfs[i][j] 表示以第 i 个元素为基准，往前 j 个元素到第 i 个元素之差之和 
long long n,m;
const long long inf=1e15;
bool o(int mi){
	bool o=0;
	for(int i=mi;i<=n;i+=1){
		long long num=0,sum=0,o1=1;
		for(int j=i;j>=i-mi+1;j--){
			if((num+sum)>m  || (num+sum)<0){
				//cout<<"Problem  sum+cf[i]: "<<sum+cf[i]<<"  m: "<<m<<"  num: "<<num<<"  cf[i]: "<<cf[i]<<"  i: "<<i<<"  j: "<<j<<"  "; 
				o1=0;
				break;
			}
			sum+=cf[j];
			num=(sum+num);
		}
		//cout<<"num: "<<num<<"  o: "<<o<<" ;  \n";
		if(o1==1){
			//cout<<"\n \n"<<"True"<<"\n \n"; 
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	long long ma=-1;
	int l=0,r=n+1;
	while(l<r-1){
		int mi=(l+r)/2;
		//cout<<"l: "<<l<<"  r: "<<r<<"  mi: "<<mi<<" \n \n"; 
		bool mii=o(mi);
		//cout<<"l: "<<l<<"  r: "<<r<<"  mi: "<<mi<<"  mii: "<<mii<<"\n \n";
		if(mii){
			l=mi;
		}
		else{
			r=mi;
		}
	}
	//cout<<"l: "<<l<<"  r: "<<r<<"\n \n";
	cout<<r;
	return 0;
}
