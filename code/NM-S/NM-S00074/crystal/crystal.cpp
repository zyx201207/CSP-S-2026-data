#include<bits/stdc++.h>
using namespace std;
int n,asize;

long long m,k;
vector<long long>a(1000000,1000000000010);
long long s[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long cnt=0,cnt1=m-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end()) ;
	s[0]=a[0];
	for(int i=1;i<n;i++){
		s[i]=a[i]+s[i-1];
	}
	int asize=1;
	while(cnt<=m){

		for(int i=0,j=i+asize;j<n&&i<n;i++){
			long long sum=(!i?s[j]:s[j]-s[i-1]);
			long long caozuo=a[j]*(asize+1)-sum;
			cnt1=cnt1<caozuo?cnt1:caozuo;
		}
		cnt=max(cnt,cnt1);
		//cout<<cnt1<<" "<<cnt<<" "<<asize<<endl;
		cnt1=9999999999999999;
		asize++;
	}
	cout<<(cnt==m?asize:asize-1);
	return 0;
}
