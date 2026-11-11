#include<bits/stdc++.h>
using namespace std;
int n,m;
long long A[200000+10],B[200000+10];
void inout(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	inout();
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>A[i];
	sort(A+1,A+n+1,cmp);
	long long ans=A[1];
	for(int i=2;i<=m;i++){
		ans=ans&A[i];
	}
	cout<<ans;
	return 0;
} 







