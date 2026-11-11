#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <stack>
using namespace std;
const int N=2e5+5;
struct abc{
	int x;
	bool is_good;
	string b;
}a[N];
int n,m,sum,lucky=2e9;
bool cmp(abc x,abc y){
	if(x.b.size()!=y.b.size())return x.b.size()>y.b.size();
	if(x.is_good==true&&y.is_good==false)return true;
	if(x.is_good==false&&y.is_good==true)return false;
	for(int i=0;i<x.b.size();i++){
		if(x.b[i]=='0')return false;
		if(y.b[i]=='0')return true;
	}
	return 1;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){   //nlogn
		cin>>a[i].x;
		if(log2(a[i].x+1)==int(log2(a[i].x+1)))a[i].is_good=true;	
		else a[i].is_good=false;	//找good数 
	}
	for(int i=1;i<=n;i++){	//nlogn 转二进制 
		int t=a[i].x;
		string s="";
		while(t>0){
			s+=char('0'+t%2);
			t/=2;
		}
		reverse(s.begin(),s.end());
		a[i].b=s;
	}
	sort(a+1,a+n+1,cmp);	//nlogn
	sum=a[1].x;
	for(int i=1;i<=m;i++){
		sum=(sum&a[i].x);
		lucky=min(lucky,a[i].x);
	}
	cout<<((sum==0)?lucky:sum);
	return 0;
}
//start 1.5h
//end 2.1h
