#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long a;
	cin>>a;
	string m7;
	long long j1=0;
	long long a1;
	char a2;	
	for(long long i=0;i<a;i++){
		cin>>a1;
		cin>>a2;
		for(long long j=0;j<a1;j++){
			m7+=a2;
			j1++;
		}
	}
	long long sum=0;
	long long ans=0;
	for(long long i=m7.size()-1;i>0;i--){
		if(m7[i]!=m7[ans]){
			sum++;
		}
		ans++;
	}
	if(sum>m7.size()*0.5){
		cout<<floor(m7.size()*0.5);return 0;
	}
	cout<<sum;
	return 0;
} 
