#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<pair<long long,char>>str;
	int len=0;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		len+=a;
		if(!str.empty()&&c==str[str.size()-1].second)str[str.size()-1].first+=a;
		else str.push_back({a,c});
	}
//	for(int i=0;i<str.size();i++)cout<<str[i].first<<" "<<str[i].second<<endl;
	int head=0,end=str.size()-1;
	if(head==end){
		cout<<0;
		return 0;
	}
//	int halfLen=len/2;
	long long ans=0;
	while(head<end){
		long long mn=min(str[head].first,str[end].first);
//		if(mn<halfLen){
			if(str[head].second!=str[end].second)ans+=mn;
//			halfLen-=mn;
			str[head].first-=mn;
			str[end].first-=mn;
			if(str[head].first==0)head++;
			if(str[end].first==0)end--;
//		}else{
//			if(if(str[head].second!=str[end].second))
//		}
		if(head>=end)break;
	}
	cout<<ans;
	
	return 0;
}