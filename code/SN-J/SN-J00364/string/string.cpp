#include<bits/stdc++.h>
using namespace std;
long long n,ans;
vector<pair<long long,char> > lets;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;char c;
		cin>>a>>c;
		lets.push_back(make_pair(a,c));
	}
	for(int i=0,j=lets.size()-1;i<j;){
		if(lets[i].second!=lets[j].second){
			ans+=min(lets[i].first,lets[j].first);
		}
		if(lets[i].first>=lets[j].first){
			lets[i].first-=lets[j].first;
			j--;
		}else{
			lets[j].first-=lets[i].first;
			i++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
