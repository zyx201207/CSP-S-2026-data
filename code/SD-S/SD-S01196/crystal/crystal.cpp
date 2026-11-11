#include<bits/stdc++.h>
using namespace std;
vector<long long> a(500005);
vector<long long> b(500005);
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ma=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.begin()+n);
	for(int i=0;i<n;i++){
		int sum=1,b=0;
		for(int j=i-1;j>=0;j--){
			b+=a[i]-a[j];
			if(b<=m){
				sum++;
			}
			else{
				break;
			}
		}
		if(sum>ma){
			ma=sum;
		}
	}
	cout<<ma;
	return 0;
}
