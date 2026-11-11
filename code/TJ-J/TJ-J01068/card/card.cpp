#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN=5e5+1,MAXM=3e5+1;
int n,m,a[MAXN],bucket[MAXM],f[MAXM],idx,s[MAXN];
bitset<MAXM> checked,_left;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            idx++;
            if(!f[a[j]]){
                f[a[j]]=idx;
            }else{
                for(int k=1;k<=idx;k++){
                    _left[a[k]]=1;
                }
                idx=f[a[j]];
            }
            for(int k=idx+1;k<=j;k++) if(!_left[a[k]]) f[a[k]]=0;
            _left.reset();
            s[idx]=a[j];
        }
        for(int j=1;j<=idx;j++){
            if(!checked[s[j]]){
                checked[s[j]]=1;
                bucket[s[j]]++;
            }
        }
        for(int j=1;j<=m;j++) f[j]=0,checked[j]=0;
        idx=0;
	}
	for(int i=1;i<=m;i++) cout<<bucket[i]<<' ';
	return 0;
}
