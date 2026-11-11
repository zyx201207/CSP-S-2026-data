#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,cnt;
long long a[100000],diff[100000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long t=a[n/2+1];
	for(long long i=1;i<=n;i++){
		diff[i]=abs(t-a[i]);
	}
	sort(diff+1,diff+1+n);
	for(int i=2;i<=n;i++){
		if(sum>m){
			break;
		}else{
			if(sum+diff[i]<=m){
				cnt++;
				sum+=diff[i];
			}else{
				break;
			}
		}
	}
	cout<<cnt+1;
	return 0;
} 
