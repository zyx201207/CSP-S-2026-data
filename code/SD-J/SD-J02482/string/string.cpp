#include<bits/stdc++.h>
using namespace std;
struct str{
	int a;
	char c;
}t[200010];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>t[i].a;
		cin>>t[i].c;
	}
	long long l=0;
	long long r=n-1;
	while(l<r){
		if(t[l].c!=t[r].c){
			ans+=min(t[l].a,t[r].a);
		}
		if(t[l].a>t[r].a){
			t[l].a-=t[r].a;
			r--;
		}else if(t[l].a<t[r].a){
			t[r].a-=t[l].a;
			l++;
		}else{
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
