#include<bits/stdc++.h>
using namespace std;
int n,m,p[500005],ans[500005];
//p[i]是每一张牌牌，ans[i]表示i能出现几次。 
void solve(int i){
	int di=i-1,b=1,a[100005],id[100005];
	//di表示现在遍历的是哪一张牌，b表示下次牌要插入的地方，a表示现在桌子上的所有牌，id[i]标记上次i出现的位置 
	for(int j=1;j<=n;j++){
		id[i]=0;
	}
	for(int j=1;j<=n;j++){
		a[i]=0;
	}
	for(int j=i;j<=i+n;j++){
		di++;
		if(di>=n){
			di=1;
		}
		if(id[p[di]]!=0){
			for(int k=id[p[di]];k<=di;k++){
				a[k]=0;
			}
			id[p[di]]=di;
			b=id[p[di]];
		}
		else{
			id[p[di]]=di;
			a[b]=p[di];
			b++;
		}
	}
	for(int j=1;j<=b;j++){
		ans[j]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
} 
