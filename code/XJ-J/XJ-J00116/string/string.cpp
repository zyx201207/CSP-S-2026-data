#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
struct node{
	char c;
	int m;
}a[N];
bool mark[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
	}
	for(int i=1;i<=n/2;i++){
		if(a[i].c!=a[n-i+1].c){
			ans+=a[i].m;
		}
	}
	cout<<ans;
	return 0;
}
