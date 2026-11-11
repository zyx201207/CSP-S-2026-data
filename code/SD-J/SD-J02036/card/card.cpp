#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[500005];
int st[500005];
int b[300005];
int top;
int y[500005];
int j[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		for(int i=x;i<=n;i++){
			for(int j=1;j<=top;j++){
				if(a[i]==st[j]){
					while(top>=j){
						top--;
					}
				}
			}
			st[++top]=a[i];
		}
		top++;
		while(top--){
			b[st[top]]++;
		}
		top=0;
		memset(st,0,sizeof(st));
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
