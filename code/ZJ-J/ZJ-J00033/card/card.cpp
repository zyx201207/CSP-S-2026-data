#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,i,j,a[500100],s[500100],l[500100],b[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	ll k;
	for(ll c=1;c<=n;c++){
		k=1;
		for(i=1;i<=m;i++){
			l[i]=0;
		}
		for(i=1;i<=n;i++){
			b[i]=0;
		}
		for(i=c;i<=n;i++){
			if(l[a[i]]==0){
				l[a[i]]=k;
				b[k]=a[i];
				k++;
			}else{
				ll t=k;
				k=l[a[i]];
				b[k]=a[i];
				k++;
				for(j=k;j<=t;j++){
					l[b[j]]=0;
				}
			}
    	}
		for(i=1;i<k;i++){
		    s[b[i]]++;
	    }
	}	
	for(i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
/*
9 3
1 2 1 3 2 3 1 2 1
10 3
3 1 2 1 3 2 3 1 2 1
*/