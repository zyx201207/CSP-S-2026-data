#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010],c[500010],cnt[300010];
ll s[300010];
bool fffff=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) fffff=false;
	}
	if(fffff){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			s[i]=s[i-1]+cnt[i];
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]!=0) cout<<s[i]<<" ";
			else cout<<"0 ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		ll qaq=0;
		for(int j=i;j<=n;j++){
			bool flag=true;
			for(int k=1;k<=qaq;k++){
				if(c[k]==a[j]){
					flag=false;
					qaq=k;
					break;
				}
			}
			if(flag){
				c[++qaq]=a[j];
			}
		}
		for(int j=1;j<=qaq;j++){
			cnt[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
