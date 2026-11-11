#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],len,cnt[300010],f[300010];
void solv(int st){
	len=0;
	memset(f,0,sizeof f);
	for(int i=st;i<=n;i++){
		if(!f[a[i]]){
			f[a[i]]++;
			b[++len]=a[i];
		}
		else{
			int pos;
			for(int j=1;j<=len;j++){
				if(b[j]==a[i]){
					pos=j;
					break;
				}
			}
			for(int j=pos+1;j<=len;j++) f[b[j]]--;
			len=pos;
		}
	}
	for(int i=1;i<=len;i++) cnt[b[i]]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) solv(i);
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}

