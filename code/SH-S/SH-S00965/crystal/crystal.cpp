#include<bits/stdc++.h>
using namespace std;
//Meow~
typedef long long bint;
bint n,m;
bint a[500105],id[500105];
bint F(bint x,bint y){
	return (id[y]-id[x])-(x-1)*(a[y]-a[x]);
}
bint best_len;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(bint i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(bint i=1;i<=n;i++){
		id[i]=id[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(bint i=1,j=1;j<=n;j++){
		if(F(i,j)<=m){
			best_len=max(best_len,j-i+1);
		}else{
			i++;
		}
	}
	cout<<best_len;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

