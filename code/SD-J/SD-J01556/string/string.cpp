#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,char> > i;
	i.push_back({0,0});
	long long c=0;
	for(int j=1;j<=n;j++){
		int a;
		char c;
		cin>>a>>c;
		i.push_back({a,c});
	}
	while(!i.empty()){
		if(i[1].second==i[i.size()-1].second){
			if(i[1].first==i[i.size()-1].first){
				i.erase(i.begin()+1);
				i.erase(i.begin()+i.size()-1);
			}
			else if(i[1].first>i[i.size()-1].first){
				i[1].first-=i[i.size()-1].first;
				i.erase(i.begin()+i.size()-1);
			}
			else{
				i[i.size()-1].first-=i[1].first;
				i.erase(i.begin()+1);
			}
		}
		else{
			if(i[1].first==i[i.size()-1].first){
				c+=i[1].first;
				i.erase(i.begin()+1);
				i.erase(i.begin()+i.size()-1);
			}
			else if(i[1].first>i[i.size()-1].first){
				c+=i[i.size()-1].first;
				i[1].first-=i[i.size()-1].first;
				i.erase(i.begin()+i.size()-1);
			}
			else{
				c+=i[1].first;
				i[i.size()-1].first-=i[1].first;
				i.erase(i.begin()+1);
			}
		}
	}
	cout<<c;
	return 0;
}
