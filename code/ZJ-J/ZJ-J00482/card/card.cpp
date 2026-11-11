#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[300005];
long long t[300005],x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(t,0,sizeof(int));
		x=0;
		for(int i=k;i<=n;i++){
			int p=0,z;
			for(int j=1;j<=x;j++){
				if(a[t[j]]==a[i]){
					p=1;
					z=j;
					break;
				}
			}
			if(p==0){
				x++;
				t[x]=i;
			}else{
				x=z;
				t[x]=i;
			}
		}
		for(int i=1;i<=x;i++){
			cnt[a[t[i]]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
