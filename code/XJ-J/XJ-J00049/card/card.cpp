#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000001],top,d[1000001];
bool b[3000009];
long long ak[10000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==false)
			{
				for(int k=1;k<=top;k++){
					b[k]=true;
				}
				b[a[j]]=false;
				top=1;
				ak[1]=a[j];
				top++;
			}
			else{
				b[a[j]]=false;
				ak[top]=a[j];
				top++;
			}
		}
		for(int j=1;j<=top;j++){
			d[ak[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<' ';
	}
} 
