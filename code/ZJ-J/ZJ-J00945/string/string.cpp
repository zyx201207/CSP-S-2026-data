#include<bits/stdc++.h>
using namespace std;
int n;
pair<long long,string> p[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i].first>>p[i].second;
	}
	for(int l=1,r=n;l<r;){
		if(p[l].second!=p[r].second){
			if(p[l].first<p[r].first){
				ans+=p[l].first;
				p[r].first-=p[l].first;
				++l;
			}else if(p[l].first>p[r].first){
				ans+=p[r].first;
				p[l].first-=p[r].first;
				--r;
			}else{
				ans+=p[l].first;
				--r;
				++l;
			}
		}else{
			if(p[l].first<p[r].first){
				p[r].first-=p[l].first;
				++l;
			}else if(p[l].first>p[r].first){
				p[l].first-=p[r].first;
				--r;
			}else{
				--r;
				++l;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
---
2
2 a
3 a
---
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/