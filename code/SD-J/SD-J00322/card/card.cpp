#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int s[N];
int a[N],b[N],c[N];
int top;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+2;j++) b[j]=0;
		top=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]>0){
				while(s[top]!=a[j]){
					b[s[top]]--;
					top--;
				}
			}else{
				top++;
				s[top]=a[j];
				b[a[j]]++;
			}
		}
		for(int i=1;i<=top;i++){
			c[s[i]]++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
