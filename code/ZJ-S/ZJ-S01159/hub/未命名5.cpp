#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<long long>a;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long cup;
		cin>>cup;
		a.push_back(cup);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n-1;i++){
		a[i]=a[i+1]-a[i];
	}
	long long cnt=m;
	long long tmp=1,maxn;
	for(int k=0;k<=n-1;)
	for(int i=k;i<n-1;i++){
		if(a[i]<a[i+1]){
			cnt-=tmp*a[i];
			if(cnt<0){
				tmp--;
				break;
			}
			tmp++;
			maxn=max(tmp,maxn);
		}else if(a[i]==a[i+1]){
			tmp++;
			continue;
		}
	}
}