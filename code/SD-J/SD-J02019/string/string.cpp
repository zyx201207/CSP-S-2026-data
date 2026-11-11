#include<bits/stdc++.h>
using namespace std;
long long sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,char> > v;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		v.push_back({x,c});
	}
	int i=0,j=n-1;
	while(i<=j){
		if(v[i].second!=v[j].second){
			if(v[i].first>v[j].first){
				sum+=v[j].first;
				v[i].first-=v[j].first;
				j--;
			}
			else if(v[i].first<v[j].first){
				sum+=v[i].first;
				v[j].first-=v[i].first;
				i++;
			}
			else{
				sum+=v[i].first;
				i++,j--;
			}
		}
		else{
			if(v[i].first>v[j].first){
				v[i].first-=v[j].first;
				j--;
			}
			else if(v[i].first<v[j].first){
				v[j].first-=v[i].first;
				i++;
			}
			else{
				i++,j--;
			}
		}
	}
	cout<<sum;
	return 0;
}
// hui guo ma??????????????
// qiu ni le,rang wo na 100pts ba!!!!!!!!!!!!!!!!!!!!
