#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,front=1,rear,cnt;
pair<long long,char>a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		if(a[rear].second==y&&i!=1){
			a[rear].first+=x;
		}
		else{
			a[++rear]={x,y};
		}
	}
	int i=front,j=rear;
	while(i<=j){
		if(a[i].second!=a[j].second){
			cnt+=min(a[i].first,a[j].first);
		}
		if(a[i].first>a[j].first){
			a[i].first-=a[j].first;
			j--;
		}
		else if(a[i].first<a[j].first){
			a[j].first-=a[i].first;
			i++;
		}
		else{
			i++;
			j--;
		}
	}
	cout<<cnt;
	return 0;
}
