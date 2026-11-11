#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[222222];
char c[222222];
long long sum;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	//deque<node> q;
	int i=1,j=n;
	while(i<=j){
		//cout<<c[i]<<c[j]<<endl;
		if(c[i]!=c[j]){
			sum+=min(a[i],a[j]);
		}
		if(a[i]>a[j]){
			a[i]-=a[j--];
		}else if(a[i]<a[j]){
			a[j]-=a[i++];
		}else{
			i++,j--;
		}
	}
	cout<<sum;
	return 0;
}
