#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a];
	for(int i = 0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a);long long cost = 0;int ccount = 1;int pre = 0;
	for(int i = 1;i<a;i++){
		if(c[i] != c[i-1]){
			cost = cost+(c[i]-c[i-1])*ccount;
		}
		ccount++;
	//	cout<<cost<<endl;
		if(cost>b){
			break;
		}
	}
	vector<int> ans;
	ans.push_back(ccount-1);
	int end = ccount-2;
	for(int i = 0;end<a and i<a;i++){
		if((c[end]-c[i])>((c[end+1]-c[end])*(end-i))){
			end +=floor((c[end]-c[i])/((c[end+1]-c[end])*(end-i)));ans.push_back(end-i+1);
		}
	}
	sort(ans.begin(),ans.end());
	int anst=ans.size()-1;
	cout<<ans[anst];
			
}
