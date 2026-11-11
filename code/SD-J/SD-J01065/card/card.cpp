#include<bits/stdc++.h>
#include<vector>
using namespace std;
long long a[500005],n,m,ans[300005];
void bu(int h,int ab,int l,bool b){
	for(int i=h+1;i<=n;i++){
		if(a[i]==ab){
			l=i;
			b=false;
			return;
		}
	}
	b=true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans[a[n]]=n;
	for(int j=1;j<=n;j++){
		int l;
		bool b;
		for(int i=j;i<n;i++){
			bu(i,a[i],l,b);
			cout<<b<<" "<<l<<endl;
			if(b){
				ans[a[i]]++;
			}
			else{
				i=l-1;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
