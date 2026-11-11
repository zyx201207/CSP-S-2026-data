#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5; 
int n,m,a[N],cnt[N],C[N],s[N],l;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int c=1;c<=n;c++){
		memset(cnt,0,sizeof(cnt));
		l=0;
		for(int i=c;i<=n;i++){
			if(cnt[a[i]]==0){
				s[++l]=a[i];
				cnt[a[i]]=l;
			}else{
				for(int j=cnt[a[i]]+1;j<=l;j++) cnt[s[j]]=0;
				l=cnt[a[i]];
			}
		}
		for(int i=1;i<=l;i++){
			C[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<C[i]<<" ";
	}
	return 0;
}