#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000010]{0};
long long sum=0;
int right_;
long long minn=10e+5;
long long summ=0;
void xxx(long long x,long long number){
//	cout<<x<<" "<<number<<endl;
	if(x==right_){
		if(minn==number){
			sum++;
		}else if(minn>number){
			minn=number;
			sum=1;
		}
		return;
	}
	long long k=x+1;
	while(abs(a[k]-a[x])<=d&&k<=n){
//		cout<<k<<" "<<number<<" "<<t<<endl;
		xxx(k,number+1);
		k++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<n-2;i++){
			for(long long j=i+3;j<=n;j++){
				sum=0;
				right_=j;
				minn=n+1;
				xxx(1,0);
				if(sum==2) summ++;
			}
		}
		cout<<summ<<endl;
	}
	return 0;
}