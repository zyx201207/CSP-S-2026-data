#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long sum[N];
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal1.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i+1]=a[i+1]-a[i];
	}
	long long maxcnt=0;
	for(int i=1;i<=n;i++){
		int x=1;
		long long mm=0,y=0;
		for(int j=i;j<=n;j++){
			mm+=sum[j]*x;
			x++;
			if(mm<=m){
				y++;
				maxcnt=max(maxcnt,y);
			}else{
				break;
			}
		}
	}
	cout<<maxcnt+1;
	return 0;
} 
