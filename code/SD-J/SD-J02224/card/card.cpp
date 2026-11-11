#include<bits/stdc++.h>
using namespace std;
struct solve{
	int i;
	bool b=false;
}sol[300010];
long long m,n,a[500010],s[300010],c[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[j]=c[j];
			sol[j].b=0;
		}
		
		for(int j=i;j<=n;j++){
			if(!sol[a[j]].b){
				sol[a[j]].b=true;
				sol[a[j]].i=j;
			}else {
				for(int k=sol[a[j]].i+1;k<=j;k++){
					if(sol[a[k]].i==k)sol[a[k]].b=false;
					a[k]=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
			s[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}

