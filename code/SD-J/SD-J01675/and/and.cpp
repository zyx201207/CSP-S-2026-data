# include <bits/stdc++.h>
using namespace std;
long long A[500100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	sort(A+1,A+1+n,cmp);
	//for(int i=1;i<=n;i++) cout<<A[i]<<' ';
	cout<<A[m];
	return 0;
} 
