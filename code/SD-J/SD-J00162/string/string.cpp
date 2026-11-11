#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
unsigned long long ans;
deque<pair<unsigned long long,char> > s;
int main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a[i],&c[i]);
		s.push_back({a[i],c[i]});
	}
	for(int i=1;i<=n;i++)
	while(!s.empty()){
		if(s.size()==1){
			break;
		}
		if(s.back().second==s.front().second){
			if(s.back().first==s.front().first){
				s.pop_back();
				s.pop_front();
			}
			else{
				if(s.back().first>s.front().first){
					unsigned long long sum=s.back().first-s.front().first;
					char x=s.back().second;
					s.pop_back();
					s.pop_front();
					s.push_back({sum,x});
				}
				else{
					unsigned long long sum=s.front().first-s.back().first;
					char x=s.front().second;
					s.pop_back();
					s.pop_front();
					s.push_front({sum,x});					
				}				
			}
		}
		else{
			if(s.back().first==s.front().first){
				ans+=s.back().first;
				s.pop_back();
				s.pop_front();
			}
			else{
				if(s.back().first>s.front().first){
					ans+=s.front().first;
					unsigned long long sum=s.back().first-s.front().first;
					char x=s.back().second;
					s.pop_back();
					s.pop_front();
					s.push_back({sum,x});
				}
				else{
					ans+=s.back().first;
					unsigned long long sum=s.front().first-s.back().first;
					char x=s.front().second;
					s.pop_back();
					s.pop_front();
					s.push_front({sum,x});					
				}
			}
		} 
	}
	printf("%d",ans);
	return 0;
}
