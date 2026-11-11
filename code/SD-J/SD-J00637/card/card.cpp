#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,m,a[500005],b[300005],c[300005],d,x,y;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			d++;
		}
	}
	if(d==0){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
			c[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<" ";
		}
	}else if(m<=2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]){
				x++;
			}else{
				x++;
				y++;
			}
		}
		if(a[n]==1){
			cout<<x<<" "<<y;
		}else{
			cout<<y<<" "<<x;
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				b[j]=0;
			}
			for(int j=i;j<=n;j++){
				if(b[a[j]]==0){
					b[a[j]]=j;
					c[a[j]]++;
				}else{
					for(int k=b[a[j]];k<=j;k++){
						if(b[a[k]]!=0){
							c[a[k]]--;
						}
						b[a[k]]=0;
					}
					b[a[j]]=j;
					c[a[j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<" "; 
		}
	}
	return 0;
}
//Trick||Treat!
