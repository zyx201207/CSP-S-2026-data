//冯睦子 SN-J00736 西安市渭北中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
}
