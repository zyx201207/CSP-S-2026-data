#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long sum=-1;
long long a[500050];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			long long m1=m;
			long long m2=1;
			for(int j=i-1;j>=1;j--){
				long long k=a[i]-a[j];
				m1-=k;
				if(m1<0) break;
				m2+=1;
			}
			//cout<<"!!! "<<m1<<" "<<m2<<endl;
			if(m2>=sum) sum=m2;
			//cout<<"s:"<<sum<<" "<<endl; 
		}
		cout<<sum<<endl;
	}
	return 0;
}

