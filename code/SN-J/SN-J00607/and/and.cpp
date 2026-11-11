#include<bits/stdc++.h>
using namespace std;
int n,m,num=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==m){
		num=a[0];
		for(int i=1;i<n;i++){
			num=num&a[i];
		}
	}
	else{
		int sum;
		for(int i=0;i<n;i++){
			sum=a[i];
			for(int j=i+1;j<m+i;j++){
				sum=sum&a[j];
			}
			if(sum>num) num=sum;
		}
	}
	cout<<num;
	return 0;
}

