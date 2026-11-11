#include<bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long a[500005];
long long cnt;
long long flag;
long long ans;
long long maxans;

int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		flag=i;
		while(flag){
			flag--;
			cnt+=(a[i]-a[flag]);
			if(cnt>m){
				break;
			}
			else{
				ans++;
			}
		} 
		if(ans>maxans){
			maxans=ans;
		}
		ans=0;
		cnt=0;
	}
	cout<<maxans+1;
	return 0;
}
