#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int r;
	int k;
	long long a[10005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	sort(i,i+1);
	k=i/n;
	}
	int l; 
	int q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>k){
			l=k-i;
		}
		if(i==k)r++;
		if(i<k){
			i+l==k;
			r++; 
			if(l>0)q++;	cout<<r;
		}
	}
	return 0;
}
