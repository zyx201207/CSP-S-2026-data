#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
	long long a,b;
};
vector<node>v;
long long a[500005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n,cmp);
	int q=a[1],cd=1;
	for(int i=2;i<=n;i++){
		if(a[i]==q){
			cd++;
		}
		else{
			v.push_back({q,cd});
			q=a[i];
			cd=1;
		}
	}
	v.push_back({q,cd});
	long long max1=-1;
	for(int i=1;i<v.size();i++){
		long long x=v[v.size()-i].a;
		long long num=0,sy=m;
		num+=v[v.size()-i].b;
		for(int j=i+1;j<=v.size();j++){
			long long y=v[v.size()-j].a;
			if((x-y)*v[v.size()-j].b<=sy){
				num+=v[v.size()-j].b;
				sy-=(x-y)*v[v.size()-j].b;
			}else{
				num+=sy/(x-y);
				break;
			}
			
		}
		max1=max(max1,num);
	}
	cout<<max1;
	return 0;
}

