#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n;
pair<int,char> temp[N];
stack<pair<int,char> > mp1,mp2;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>temp[i].first>>temp[i].second;
		mp1.push(temp[i]);
	}
	for(int i=n;i>=1;i--){
		mp2.push(temp[i]);
	}
	while(mp1.size()||mp2.size()){
		pair<int,char> q=mp1.top(),p=mp2.top();
		int x=q.first,y=p.first;
		char a=q.second,b=p.second;
		mp1.pop();
		mp2.pop();
		if(a==b){
			if(x>y){
				mp1.push({x-y,a});
			}
			else if(x<y){
				mp2.push({y-x,b});
			}
		}
		else{
			if(x>y){
				ans+=y;
				mp1.push({x-y,a});
			}
			else if(x<y){
				ans+=x;
				mp2.push({y-x,b});
			}
			else if(x==y){
				ans+=x;
			}
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}
