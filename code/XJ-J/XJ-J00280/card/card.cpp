#include<bits/stdc++.h>
using namespace std;
int n,m,b[200005],ans[300005];
void f(int p){
	if(p==0){
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return;
	}
	for(int i=1;i<=p;i++){
		for(int j=1;j<=i;j++){
			if(b[i]==b[j]){
				for(int l=j;l<=p-abs(j-i);l++){
					b[l]=b[l+p-abs(j-i)];
					p--;
				}
				i = j;
				continue;
			}
		}
	}
	for(int i=1;i<=p;i++){
		ans[b[i]]+=1;
	}
	f(p);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	f(n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}