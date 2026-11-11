#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+100;
long long n,m,a[N],sum;
int check(int x){
	int t=m,cnt=1;
	while(t){
		for(int i=x;i>=1;i--){
			if(a[x]-a[i-1]<=t){
				t-=a[i]-a[i-1];
				cnt++;
			}else{
				break;
			}
		}
		break;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	bool flag=true;
	for(int i=1;i<=n-1;i++){
		if(a[i]!=a[i+1]){
			flag=false;
		}
	}
	if(flag==true){
		cout<<max(n-m%n,m%n);
	}
	long long pu=floor(sum*1.0/n);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]<=pu&&a[i+1]>pu){
			int an1=check(i);
			int an2=check(i+1);
			cout<<max(an1,an2);
			return 0;
		}
	}
	return 0;
} 
//7 4
//7 98 45 6 3 7 0
