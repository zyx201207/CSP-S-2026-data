#include<bits/stdc++.h>
using namespace std;
long long n,sum,pos,s,cnt;
pair<int,char> a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		sum+=a[i].first;
	}
	pos=sum/2;
	
	int i=0,j=n; 
	while(1){
		i++;
		s=min(s+a[i].first,pos);
		while(a[i].first>0){
			if(i==j){
				break;
			}
			if(a[j].second!=a[i].second) cnt+=min(a[i].first,a[j].first);
			a[i].first-=a[j].first;
			a[j].first=-a[i].first;
			if(a[j].first<=0)j--;
		}
		if(s==pos) break;
	}
	cout<<cnt;
	return 0;
}
