#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
vector<pair<long long,char> > a(n);
for(long long i=0;i<n;i++){
	cin>>a[i].first>>a[i].second;
}
cnt=0;
vector<pair<long long ,char> > b=a;
reverse(b.begin(),b.end());
for(int i=0,j=n-1;i<n,j>=0;){
	if(a[i].second!=b[j].second){
		if(a[i].first>=b[j].first){
			a[i].first-=b[j].first;
			cnt+=b[j].first;
			b[j].second=a[i].second;
			b[j].first=0; 
		}else{
			b[j].first-=a[i].first;
			cnt+=a[i].first;
			a[i].second=b[j].second;
			a[i].first=0;
		}
	}else{
	if(a[i].first>=b[i].first){
		a[i].first-=b[j].first;
	}else{
		b[j].first-=a[i].first;
	}
	}
	if(a[i].first==0)i++;
	if(b[j].first==0)j--;
}

cout<<cnt/2;
	return 0;
}
