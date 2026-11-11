#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;cin>>n,m;
	vector<int>r(n);
    for(int i=1;i<=n;++i){
    	cin>>r[i];
	}
	int mx=-1;
	if(m==1){
		for(int i=1;i<=n;++i){
			mx=max(mx,r[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		vector<int>a(n);
	vector<int>b(n);
	vector<int>c(n);
	int sum=0;
	int mx=-1;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int sum1=1,sum2=1;
		    while(i!=0){
		    a[sum1]=i%2;
		    i/=2;
		    sum1++;
	        }
	        while(j!=0){
		    b[sum]=j%2;
		    j/=2;
		    sum2++;
	        }
	        int sum3=max(sum1,sum2);
	        for(int i=sum3;i>=1;--i){
	        	c[i]=a[i]&&b[i];
	        }
	        for(int i=1;i<=sum3;++i){
	        	int x=2;
	        	sum+=c[i]*x;
	        	x*=2;
			}
			mx=max(mx,sum);
			sum=0;
	    }
	}
	cout<<mx;
}
	return 0;
	}