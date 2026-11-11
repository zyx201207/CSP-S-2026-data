#include<bits/stdc++.h>//Trick||Treat!
using namespace std;
const int N=1e5*2+5;
int a[N];
char c[N];
int i_i[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,l=0;
	cin>>n;
	string s="";
	string sr="";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s=s+c[i];
		sr=c[i]+sr;
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		if(c[1]==c[2]){
			cout<<0;
		}else{
			cout<<min(a[1],a[2]);
		}
	}else{
		int l=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			l++;
			if(s[i]!=sr[i]){
				i_i[l]=i;
			}
		}
		for(int i=1;i<=l;i++){
			ans+=a[i_i[i]];
		}
		cout<<ans;
	}
	return 0;
}