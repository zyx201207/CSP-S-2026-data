#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopne("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long j=0;j<n;j++){
		cin>>a[j];
	}
	sort(a,a+n-1);
	long long i=0;
	while(m>=0){
		if(a[i]+1<a[i+1]){
			a[i]++;
			m-=i;
		}else{
			m-=i;
			i++;
		}
	}
	cout<<i+1<<endl;
	return 0;//PLEASE AC;
}
