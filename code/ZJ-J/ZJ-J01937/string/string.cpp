#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	int data;
	char a;
}e[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>e[i].data>>e[i].a;
	}
	int i=1,j=n;
	while(i<j){
		int t=min(e[i].data,e[j].data);	
		if(e[i].a!=e[j].a){
			ans+=t;
		}
		e[i].data-=t;
		e[j].data-=t;
		if(e[i].data==0)i++;
		if(e[j].data==0)j--;
	}
	cout<<ans;
	return 0;
}
