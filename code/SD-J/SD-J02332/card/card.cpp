#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],t;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ll st[500010]={0},top=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=j;k++){
				if(st[k]==a[j]){
					while(top>=k){
					top--;
					}
					break;
				} 	
			}
				st[++top]=a[j];
		}
		for(int j=1;j<=top;j++){
			t[st[top]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	} 
	return 0;
}
