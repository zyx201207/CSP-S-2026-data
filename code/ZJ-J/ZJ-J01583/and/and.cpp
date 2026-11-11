#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=0;
	for(int i=1;i<=n;i++){
		int sum=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			sum&=a[j];
		}
		num=max(num,sum);
		
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
}