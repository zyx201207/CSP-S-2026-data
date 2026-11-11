#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a;
long long b[300010]{0};
vector<long long> c;
long long cnt=0;
long long find(long long x){
	for(long long i=0;i<cnt;i++){
		if(c[i]==x) return i+1;
	}
	return 0;
}
void clean(long long x){
	for(long long i=x;i<cnt;i++) c.pop_back();
	cnt=x;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	  
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
    cin>>n>>m;
	for(long long i=0,k;i<n;i++){
		cin>>k;
		a.push_back(k);
	}
	for(long long i=0;i<n;i++){
		c.clear();
		cnt=0;
		for(long long j=i;j<n;j++){
			if(!find(a[j])){
				c.push_back(a[j]);
				cnt++;
			}else{
				clean(find(a[j]));
			}
		}
		long long teep=cnt-1;
		for(long long j=0;j<cnt;j++){
			b[c[teep]]++;
			c.pop_back();
			teep--;
			
		}
	}
	for(long long i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
