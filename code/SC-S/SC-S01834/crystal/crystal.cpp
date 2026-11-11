#include<iostream>
#include<algorithm>
using namespace std;
long long a[500010];
long long s[500010];
long long n,m;
bool check(long long x){
	long long sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[i];
	}
	//cout<<sum<<' '<<s[x]<<"\n";
	long long res=x*a[x]-sum;
	if(res<=m){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long ss;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		ss+=a[i];
	}
	//cout<<ss<<" "<<s[n]<<"\n";
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)==1){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
} 
/*
5 5
1 2 4 8 9
      l
    r
      m
5 8
-3 -1 2 2 7
-1 -3 2 2 7
            l
          r
            m   
			5 10
5 10
-10 -1 -3 -3 -2  
-1	-2	-3	-3	-10	-18
			l
					r
       			m    
*/