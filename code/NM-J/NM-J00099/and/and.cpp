#include<bits/stdc++.h>
using namespace std;
long long n, m;
int ans[100005]={0};
long long maxn=-1;
int s(int a,int b){
	return a & b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ans[i];
	} 
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(s(ans[i],ans[j])>maxn) maxn=s(ans[i],ans[j]);
		}
	}
	cout<<maxn;
    return 0;
}
