#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],p[N],b[N],s[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++){
			int pos=0;
			p[++k]=a[j];
			s[a[j]]++;
			if(s[a[j]]>=2){
				for(int w=1;w<=j;w++){
					if(p[w]==p[j]){
						pos=w;
						//cout<<pos;
						break;
					}
				}
				for(int w=j;w>=pos;w--){
					p[w]=0;
					k--;
				}
				p[++k]=a[j];
				s[a[j]]=1;
			}
			//cout<<p[k]<<" "<<k<<" "<<s[a[j]]<<" "<<j<<" "<<i<<"""\n";
		}
		for(int zz=1;zz<=k;zz++){
			b[p[zz]]++;
		}
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}












