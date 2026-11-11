#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,summ=0,sum=0;
	vector<char>v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].c;
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i].num;j++){
			v.push_back(a[i].c);
		}
	}
	for(long long i=0,j=v.size()-1;i<=v.size()/2,j>=v.size()/2;i++,j--){
		if(v[i]!=v[j]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
