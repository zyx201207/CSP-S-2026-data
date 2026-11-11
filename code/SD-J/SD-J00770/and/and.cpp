#include<bits/stdc++.h>
using namespace std;
int n,m;
long long an[200100];
long long cnt=0;
long long ad(int st,int mk,long long ne){
	if(mk==0){
		return ne;
	}
	for(int i=st+1;i<=n;i++){
		cnt=max(cnt,ad(i,mk-1,ne&an[i]));
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int i,j;
	long long maxm=0;
	for(i=1;i<=n;i++){
		cin>>an[i];
	}
	for(i=1;i<=n-m;i++){
		maxm=max(maxm,ad(i,m-1,an[i]));
	}
	cout<<maxm<<'\n';
	return 0;
} 
