#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[500010];
ll b[500010];
ll cnt[300010];
ll firstpos[300010];
ll secondpos[300010];
bool use[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(firstpos[a[i]]==0){
			firstpos[a[i]]=i;
			secondpos[a[i]]=0;
		}
	}
	ll pos=0;
	for(ll turn=1;turn<=n;turn++){
		for(ll i=turn;i<=n;i++){
			if(secondpos[a[i]]==0){
				secondpos[a[i]]=pos+1;
				b[pos+1]=a[i];
//				cout<<b[pos+1]<<endl;
//				cout<<"!\n";
				pos++;
			}
			else{
				if(pos==0){
					pos=secondpos[a[i]];
				}
				pos=min(secondpos[a[i]],pos);
			}
			if(secondpos[a[i]]>pos){
				pos++;
				b[pos]=a[i];
				secondpos[a[i]]=pos;
			}
		}
//		cout<<"B: ";
		for(ll i=1;i<=pos;i++){
//			cout<<b[i]<<" ";
			if(!use[b[i]]){
				use[b[i]]=true;
			}
			else continue;
			cnt[b[i]]++;
		}
//		cout<<endl;
		pos=0;
		for(ll i=1;i<=n;i++){
			b[i]=0;
			secondpos[a[i]]=0;
			use[a[i]]=false;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
