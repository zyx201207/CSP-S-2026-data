#include<bits/stdc++.h> 
using namespace std;
int n,a;
long long ans;
char c;
deque<pair<int,char>>s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		s.push_back({a,c});
	}
	while(s.size()){
		if(s.size()==1)break;
		pair<int,char>t1=s.back(),t2=s.front();
		s.pop_back();
		s.pop_front();
		if(t1.first==t2.first&&t1.second!=t2.second)ans+=t1.first;
		else if(t1.first<t2.first){
			if(t1.second!=t2.second)ans+=t1.first;
			t2.first-=t1.first;
			s.push_front(t2);
		}
		else if(t1.first>t2.first){
			if(t1.second!=t2.second)ans+=t2.first;
			t1.first-=t2.first;
			s.push_back(t1);
		}
	}
	cout<<ans;
	return 0;
}
