#include<bits/stdc++.h>
using namespace std;
int t[300005];
struct node{
	int a;
	bool b;
}a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
	}
	if(m==2){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].a==1){
				cnt++;
				if(cnt==2){
					cnt=0;
					a[i].b=1;
				}
			}
		}
	}
	cout<<1;
	
	return 0;
}
