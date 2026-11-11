#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
long long a[100005],s[100005];
bool cmp(int A,int B){
	return A>B;
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	s=sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		sum=sum,and,s[i];
	}
	cout<<sum;


	return 0;
}
