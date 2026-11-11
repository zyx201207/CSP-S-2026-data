#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

long long a[200010];
long long countone(long long x){
	string str="";
	while(x>0){
		string ch="";
		ch+=x%2+'0';
		str.insert(0,ch);
		x/=2;
	}
	long long ans=0;
	while(str.find("1")!=-1){
		ans++;
		str.erase(str.find("1"),1);
	}
	return ans;
}
bool cmp(int a,int b){
	if(countone(a)!=countone(b)){
		return countone(a)>countone(b);
	}
	return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
