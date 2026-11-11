#include<bits/stdc++.h>
using namespace std;
int n;
long long len;
char ch;
long long ans;
deque< pair<long long,char> >a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len;
		cin>>ch;
		a.push_back({len,ch});
	}
	while(a.size()>1){
		if(a.front().second==a.back().second){
			if(a.front().first==a.back().first){
				a.pop_front();
				a.pop_back();
			}
			else if(a.front().first>a.back().first){
				long long f1=a.front().first,f2=a.back().first;
				char ch1=a.front().second;
				a.pop_front();
				a.pop_back();
				a.push_front({f1-f2,ch1});
			}
			else {
				long long f1=a.front().first,f2=a.back().first;
				char ch2=a.back().second;
				a.pop_front();
				a.pop_back();
				a.push_back({f2-f1,ch2});
			}
		}
		else{
			if(a.front().first==a.back().first){
				ans+=a.front().first;
				a.pop_front();
				a.pop_back();
			}
			else if(a.front().first>a.back().first){
				long long f1=a.front().first,f2=a.back().first;
				char ch1=a.front().second;
				ans+=f2;
				a.pop_front();
				a.pop_back();
				a.push_front({f1-f2,ch1});
			}
			else {
				long long f1=a.front().first,f2=a.back().first;
				char ch2=a.back().second;
				ans+=f1;
				a.pop_front();
				a.pop_back();
				a.push_back({f2-f1,ch2});
			}
		}
	} 
	cout<<ans;
	return 0;
}
