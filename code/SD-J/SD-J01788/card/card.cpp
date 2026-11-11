#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int d[500005];
bool v[500005];
int t[300005];
int top=-1;
void pj(){
	for(int i=0;i<n;i++){
		for(int j=i;j<=n;j++){
			if(!v[a[j]]){
				d[++top]=a[j];
				v[a[j]]=1;
			}
			else{
				while(1){
					if(a[j]==d[top]){
						break;
					}
					v[d[top]]=0;
					top--;
				}
			}
		}
		for(int j=0;j<=top;j++){
			v[d[j]]=0;
			t[d[j]]++;
		}
		top=-1;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	pj();
	return 0;
}

