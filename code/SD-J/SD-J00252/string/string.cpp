#include<bits/stdc++.h>
using namespace std;
long long n,a=0,k=0,l=0,r;
pair<long long,char>s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n-1;
	while(n--){
		long long k1;
		char c;
		cin>>k1>>c;
		s[k]={k1,c};
		k++;
	}
	while(l<r){
		if(s[l].first<=s[r].first){
			if(s[l].second!=s[r].second)a+=s[l].first;
			s[r].first-=s[l].first;
			s[l].first=0;
		}else{
			if(s[l].second!=s[r].second)a+=s[r].first;
			s[l].first-=s[r].first;
			s[r].first=0;
		}
		if(s[l].first==0)l++;
		if(s[r].first==0)r--;
	}cout<<a;
	return 0;
}
