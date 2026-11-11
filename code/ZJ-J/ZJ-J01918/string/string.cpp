#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream("string.in");
	ofstream("string.out");
	int a;
	cin >> a;
	vector<pair<long long,char> > b;
	long long t,ans=0;
	char k;
	for(int i=0;i<a;i++){
		cin >> t >> k;
		b.push_back({t,k});
	}
	for(int i=0,j=b.size()-1;i<j;){
		if(b[i].second!=b[j].second){
			if(b[i].first<b[j].first){
				ans+=b[i].first;
				b[j].first-=b[i].first;
				i++;
			}
			else if(b[i].first>b[j].first){
				b[i].first-=b[j].first;
				ans+=b[j].first;
				j--;
			}
			else{
				ans+=b[j].first;
				i++,j--;
			}
		}
		else{
			if(b[i].first<b[j].first){
				b[j].first-=b[i].first;
				i++;
			}
			else if(b[i].first>b[j].first){
				b[i].first-=b[j].first;
				j--;
			}
			else{
				i++,j--;
			}
		}
	}
	cout << ans;
	return 0;
}
