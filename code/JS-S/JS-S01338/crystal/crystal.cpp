#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		long long n,m;
		cin>>n>>m;
		vector<long long> v(n);
		for(long long i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		long long num=1;
		long long sum=0;
		long long l=0;
		for(long long i=1;i<n;i++){
			sum+=v[i]-v[i-1]+(i-1-l)*(v[i]-v[i-1]);
			if(sum<=m){
				num=max(num,i-l+1);
			}else{
				while(sum>m){
					sum-=v[i]-v[l];
					l++;
				}
			}
		}
		cout<<num;
		return 0;
}
