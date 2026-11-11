#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long s[N];
long long b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s+0,s+n);
	long long cha=s[1]-s[0];
	long long idx=0;
	long long ans=0;
	long long t=0;
	for(int i=0;i<n;i++){
		b[s[i]]++;
	}

	for(int i=0;i<n;i++){
		ans=max(b[s[i]],ans);
	}
	for(int j=0;j<n;j++){
		if(idx*cha>m){
			break;
		}
		idx+=j;
		t++;
	}
	if(ans>=t){
		cout<<ans;
	}
	else{
		if(idx*cha>m){
			cout<<t-1;
		}
		else if(t>n){
            cout<<t-1;
		}
		else{
			cout<<t;
		}
	}
	return 0;
}
