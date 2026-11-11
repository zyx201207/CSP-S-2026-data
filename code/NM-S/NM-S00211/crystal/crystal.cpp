#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		long long cnt=0,f=0,water=1;
		for(int j=i-1;j>=1;j--){
			cnt+=(a[i]-a[j]);
			water++;
			if(cnt>m){
				f=1;
				break;
			}
		}
		if(f==0){
			cout<<water<<endl;
			break;
		}
	}
	return 0;
}
