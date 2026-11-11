#include<bits/stdc++.h>
#define LL long long int
using namespace std;
int a[200009],s[30],Log[200009],n,m,b[200009];
int LOG(int x){
	if(x==0){
		return 0;
	}
	int sum=LOG(x/2)+1;
	if(x<200009){
		if(Log[x]!=0){
			return Log[x];
		}
		Log[x]=sum;
	}
	return sum;
}
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	Log[0]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int sum=LOG(a[i]);
		s[sum]=i;
		b[i]=sum;
	}
	sort(b+1,b+n+1);
	cout<<a[s[b[n-m+1]]];
}		