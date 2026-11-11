#include<bits/stdc++.h>
using namespace std;
long long n,o[1000000],ans,s;
string q[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>o[i]>>q[i];
	}
	s=n-1;
	for(long long i=0;i<n;i++){
		string a=q[i];
		for(long long j=s;j>=i;j--){
			if(o[i]<=0 || o[j]<=0){
				break;
			}
			if(q[j]==a){
				long long w=o[i];
				o[i]-=o[j];
				o[j]=max(0ll,o[j]-w);
				if(o[j]==0) s--;
			}
			else{
				long long w=o[i],l=o[j];
				o[i]-=o[j];
				o[j]=max(0ll,o[j]-w);
				if(o[j]==0) s--;
				ans+=(l-o[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}
