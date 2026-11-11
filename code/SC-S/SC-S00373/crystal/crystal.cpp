#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int maxx=0;
	for(int i=1;i<=n;i++){
		int sum=0,s;
		for(int j=i;j<=n;j++){
			sum+=a[i]-a[j];
			if(sum>m){
				s=j-i-1;
				break;
			}
			 if(j==n&&sum<=m){
				s=j-i;
			}
		}
		
		maxx=max(maxx,s);
		
	}
	cout<<maxx+1;
	
}