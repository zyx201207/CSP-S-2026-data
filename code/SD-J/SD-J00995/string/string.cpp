#include<bits/stdc++.h>
using namespace std;
struct x{
	int m;
	char c;
}ar[200005]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i].m>>ar[i].c;
	}
	long long ans=0;
	int l=1,r=n;
	while(l<=r){
		long long ll=min(ar[l].m,ar[r].m);
		ar[l].m-=ll;
		ar[r].m-=ll;
		if(ar[l].c!=ar[r].c){
			ans+=ll;
		}
		if(ar[l].m==0){
			l++;
		}else{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
