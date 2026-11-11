#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int q[500005];
int mid[300005];
int top=0;

bool f[300005];
void push(int x){
	q[++top]=x;
}
void pop(){
	top--;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int tmp=n;
	int k=1;
	while(tmp--){
		
		top=0;
		memset(q,0,sizeof(q));
		memset(f,0,sizeof(f));
		for(int i=k;i<=n;i++){
			if(f[a[i]]==0){
				push(a[i]);
				f[a[i]]=1;				
			}		
			else{
				while(q[top]!=a[i]){
					f[q[top]]=0;
					pop();
				}				
			}
			
		}
		
		for(int i=1;i<=top;i++){
			mid[q[i]]++;
		}
		k++;
	}
	for(int i=1;i<=m;i++){
		cout<<mid[i]<<" ";
	}
	return 0;
}
