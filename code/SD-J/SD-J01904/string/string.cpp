#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	
	int r,s=0;
	cin>>r;
	for(int i=1;i<=r;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=r;
	while(i != j){
		
		int q=min(a[i],a[j]);
		
		a[i]-=q;
		a[j]-=q;
		
		if(c[i]==c[j]) q=0;
		
		if(a[i]==0) i++;
		else j--;
		
		s+=q;
	}
	cout<<s<<"\n";
	return 0;
}
