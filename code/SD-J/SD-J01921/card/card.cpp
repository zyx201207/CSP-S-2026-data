#include<bits/stdc++.h>
using namespace std;
int st[300100],a[301000],t[1010000],dis[300100],lst[300100];
int n,m,top=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(t[a[i]]==0){
			t[a[i]]++;
			++top;
			st[top]=a[i];
		}
		if(t[a[i]]!=0){
			while(1){
				if(st[top]==a[i]) break;
				t[st[top]]=0;
				top--;
			} 
		}
		for(int i=1;i<=top;i++){
			cout<<st[i]<<' ';
			dis[st[i]]++;
		}
		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<dis[i]<<' ';
	}
	return 0;
}

