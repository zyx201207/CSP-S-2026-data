#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[500005],table[500005];
bool t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	int n_1=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n_1--){
		x++;
		for(int i=0;i<=500005;i++){
			table[i]=0;
			t[i]=0;
		}
		for(int i=x;i<=n;i++){
			if(!(t[a[i]])){
				table[i-x]=a[i];
				t[a[i]]++;
			}
			else{
				for(int j=i-1;;j--){
					if(table[j]==a[i])break;
					t[table[j]]-=1;
					table[j]=0;
				}
			}
		}
		for(int i=0;i<=n;i++){
			ans[table[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
