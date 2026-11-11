#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],f[500005],f1[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	string s,s2,s1,s3;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s2+=(a[i]+'0'); 
	}
	for(ll i1=1;i1<=n;i1++){
		s=s2;
		memset(f,0,sizeof(f));
	for(ll i=i1;i<=n;i++){
		s1=(a[i]+'0');
		//cout<<s1<<endl;
		if(s.find(s1)!=-1){
			//cout<<1<<endl;
			s.erase(s.find(s1)+1);
		}
		else{
			s+=s1;
		}
	}
		//cout<<s;
		for(ll i11=1;i11<=m;i11++){
			s3=(i11+'0');
			if(s.find(s3)!=-1){
				f[i11]++;
			}
		}
		for(ll i=1;i<=m;i++){
			if(f[i]>0){
				f1[i]++;
			}
		}
		cout<<endl;
	}
	for(ll i=1;i<=m;i++){
		cout<<f1[i]<<" ";
	}
	return 0;
}
