#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn];
int n;
long long m;
long long cf[maxn];
int main(){
	freopen("crystal.in",'r',stdin);
	freopen("crystal.out",'w',stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	int base=n/2+1;
	for(int i=1;i<=n;i++){
		cf[i]=abs(a[base]-a[i]);
	}
	sort(cf+1,cf+n+1);
	long long sum=0;
	int t=0;
	int i=1;
	long long len=0;
	for(int i=1;i<=n;i++){
		len+=cf[i];
	}
	if(len<=m){
		cout<<n;
		return 0;
	}
	while(sum<=m){
		sum+=cf[i];
		i++;
		t++;
		if(sum>m){
			t--;
			break;
		}
		
	}
	cout<<t;	
	return 0;
}