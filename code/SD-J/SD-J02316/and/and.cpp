#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string b[1000000];
int a[1000000],Max=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(log(a[1])==floor(log(a[1]))){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

