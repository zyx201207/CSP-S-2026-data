#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
long long n,m;
long long man=-1,q;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m=1){
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>man){
				man=a[i];
			}
		}
		cout<<man;
	} 
	else if(m=n){
		cin>>q;
		for(int i=1;i<n;i++){
			cin>>a[i];
			q=q&a[i];
		}
		cout<<q;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			while(a[i]){
				if(a[i]%2==1){
					b[i]++;
				}
				a[i]/=2;
			}
			sort(b+1,b+1+n,cmp);
		}
		q=b[1];
		for(int i=2;i<=m;i++){
			q=q&b[i];
			cout<<q;
		}
	}
	
	
	return 0;
}
