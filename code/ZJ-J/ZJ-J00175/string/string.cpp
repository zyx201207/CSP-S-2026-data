#include<bits/stdc++.h>
using namespace std;
long long l,r,n,sum;
char s;
vector<pair<int,char>>st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>sum>>s;
		st.push_back({sum,s});
	}
	l=0,r=n-1;
	long long ans=0;
	while(l<=r){
		long long f1=st[l].first,s1=st[l].second,f2=st[r].first,s2=st[r].second;
		if(s1==s2)
			if(f1>f2)st[l].first-=f2,r--;
			else if(f1<f2)st[r].first-=f1,l++;
			else l++,r--;
		else
			if(f1>f2)ans+=f2,st[l].first-=f2,r--;
			else if(f1<f2)ans+=f1,st[r].first-=f1,l++;
			else ans+=f1,l++,r--;
	}
	cout<<ans;
}