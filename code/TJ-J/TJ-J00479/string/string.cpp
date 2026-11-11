#include<bits/stdc++.h>
using namespace std;
long long n,ans;
vector<pair<long long,char> >p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		p.push_back({a,c});
	}int num=p[0].first,lr=0,l=0,r=n-1;
	while(l<r){
		if(num==0)num=p[l].first;
		if(lr==0){
			if(num<p[r].first){
				lr=1;
				num=p[r].first-num;
				if(p[l].second!=p[r].second)
					ans+=num;
				l++;
			}else if(num>p[r].first){
				num=num-p[r].first;
				if(p[l].second!=p[r].second)
					ans+=p[r].first;
				r--;
			}else if(num==p[r].first){
				num=0;
				if(p[l].second!=p[r].second)
					ans+=p[r].first;
				l++,r--;
			}
		}
		if(lr==1){
			if(num<p[l].first){
				lr=0;
				num=p[r].first-num;
				if(p[l].second!=p[r].second)
					ans+=num;
				r--;
			}else if(num>p[l].first){
				num=num-p[l].first;
				if(p[l].second!=p[r].second)
					ans+=p[l].first;
				l++;
			}else if(num==p[r].first){
				lr=0;
				num=0;
				if(p[l].second!=p[r].second)
					ans+=p[r].first;
				l++,r--;
			}
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
