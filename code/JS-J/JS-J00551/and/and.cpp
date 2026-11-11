#include <bits/stdc++.h>
using namespace std;
unsigned long long maxx=0;
int n,m;
vector<unsigned long long> a;
void xxx(int x,int xx,unsigned long long sum){
	if(x==m){
		maxx=max(maxx,sum);
		return;
	}
	if(x==0){
		for(int i=0;i<n-m;i++){
			xxx(1,i+1,a[i]);
		}
	}
	for(int i=xx;i<=n-m+x;i++){
		xxx(x+1,i+1,sum&a[i]);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	  
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	
    cin>>n>>m;
    unsigned long long k;
    for(int i=0;i<n;i++){
		cin>>k;
		a.push_back(k);
    }
    xxx(0,0,1);
    cout<<maxx;
	return 0;
}
