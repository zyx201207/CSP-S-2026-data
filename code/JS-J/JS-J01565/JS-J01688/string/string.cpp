#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l;
	cin>>n;
	vector<long long>v1;
	vector<char>v2;
	for(long long i=0;i<n;i++){
		long long a1;
		char a2;
		cin>>a1>>a2;
		l+=a1;
		v1.push_back(a1);
		v2.push_back(a2);
	}
	long long ans=0,j=n-1,k=v1[j];
	for(long long i=0;i<n;i++){
		long long a=v1[i];
		char b=v2[i];
		while(a>k){
			a-=k;
			if(v2[j]!=b){
				ans+=k;
			}
			j--;
			k=v1[j];
		}
		k-=a;
		if(v2[j]!=b){
			ans+=a;
		}
	}
	cout<<ans/2;
	return 0;
}
