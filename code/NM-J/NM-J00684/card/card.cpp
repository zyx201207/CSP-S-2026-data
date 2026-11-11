#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=2*1e5+10;
long long a[N];
long long ans=0;
long long b[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("card.in","r",stdin);
	freoprn("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		q.push(a[i]);
		b[a[i]]++;
	} 
	
	
	return 0;
}
