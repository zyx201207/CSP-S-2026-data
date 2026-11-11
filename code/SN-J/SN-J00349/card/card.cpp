#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int a[n+5],ans[n];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<n<<" "<<n%3<<" "<<n-n/3;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
