#include<bits/stdc++.h>
using namespace std;
int W[100005];
int N[200005];
char M[200005];
int w=1;
void p(string x){
	reverse(x.begin(),x.end());
	if(w<int(x.size())) w=int(x.size());
	for(int i=0;i<x.size();i++){
		W[i+1]+=int(x[i]-'0');
		for(int j=i+1;;j++){
			if(W[j]<10) break;
			W[j]-=10;
			W[j+1]+=1;
		}
	}
	if(W[w+1]!=0){
		w++;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		N[i]=a;
		M[i]=b;
	}
	int l=1,r=n;
	while(l<r){
		if(M[l]!=M[r]) p(to_string(min(N[l],N[r])));
		int mn=min(N[l],N[r]);
		N[l]-=mn;
		N[r]-=mn;
		if(N[r]==0) r--;
		if(N[l]==0) l++;
	}
	for(int i=w;i>=1;i--){
		cout<<W[i];
	}
	return 0;
} 
