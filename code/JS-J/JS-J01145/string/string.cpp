#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],mid,now=0,ans;
char c[200005],nowa='#',nowb='#';
vector<pair<pair<long long,char>,bool> > vec;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
	    cin>>a[i]>>c[i];
	    mid+=a[i];
	}
	mid=(mid+1ll)/2ll;
	long long sum=0,len=0;
	vec.push_back(make_pair(make_pair(0,c[0]),0));
	len++;
	for (int i=0;i<n;i++){
		sum+=a[i];
		if (sum>=mid)
		  break;
		vec.push_back(make_pair(make_pair(sum,c[i+1]),0));
		len++;
	}
	sum=0;
	vec.push_back(make_pair(make_pair(0,c[n-1]),1));
	len++;
	for (int i=n-1;i>=0;i--){
		sum+=a[i];
		if (sum>=mid)
		  break;
		vec.push_back(make_pair(make_pair(sum,c[i-1]),1));
		len++;
	}
	sort(vec.begin(),vec.end());
	for (int i=0;i<len;i++){
		if (nowa!=nowb)
		  ans+=vec[i].first.first-now;
		now=vec[i].first.first;
		if (vec[i].second)
		  nowb=vec[i].first.second;
		else
		  nowa=vec[i].first.second;
	}
	if (nowa!=nowb)
	  ans+=mid-now;
	cout<<ans;
	return 0;
}
