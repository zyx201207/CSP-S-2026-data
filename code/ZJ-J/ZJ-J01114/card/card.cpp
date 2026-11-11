#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[500010];
long long s[300010]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			s[a[i]]+=a[i]*l;
			l++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}