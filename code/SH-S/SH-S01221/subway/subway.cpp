#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,m,n,d,q;
long long exitin[N],x,y,ayes[N],byes[N];
struct s{long long sta,tim;
};
s a[N],b[N];
long long p[510][1010];
int main(){
	
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>exitin[i];
	if(c==20||c==21){
	
		int an,bn;
		long long minch=1e9+10;
		cin>>an;
		for(int i=1;i<=an;i++){
			cin>>a[i].sta>>a[i].tim;
			ayes[a[i].sta]=a[i].tim;
		}
		cin>>bn;
		for(int i=1;i<=bn;i++){
			cin>>b[i].sta>>b[i].tim;
			byes[b[i].sta]=b[i].tim;
		}
		for(int i=1;i<=m;i++){
			if(ayes[i]&&byes[i])
				minch=min(minch,ayes[i]+byes[i]);
		}
//		cout<<minch<<endl;
		while(q--){
			long long minn=1e9+10;
			cin>>x>>y;
			if(ayes[x]!=0&&ayes[y]!=0)
			minn=min(minn,ayes[x]+ayes[y]);
			if(byes[x]!=0&&byes[y]!=0)
			minn=min(minn,byes[x]+byes[y]);
			if(ayes[x]&&byes[y])
			minn=min(minn,ayes[x]+byes[y]+minch);
			if(ayes[y]&&byes[x])
			minn=min(minn,ayes[y]+byes[x]+minch);
			cout<<minn+exitin[x]+exitin[y]<<endl;
		}
		return 0;
	}
	
	return 0;
	
} 
