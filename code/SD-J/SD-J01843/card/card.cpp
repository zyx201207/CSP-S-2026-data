#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans[N],s[N],maxx;
bool flag=true;
map<long long,long long>t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=false;
		t[a[i]]++;
		maxx=max(maxx,t[a[i]]);
	}
	if(flag) for(int i=1;i<=n;i++) if(a[i]!=a[i+1]) ans[a[i]]=i;
	else if(maxx==1) for(int i=1;i<=n;i++) ans[a[i]]=i;
	else if(n<=1e4){
		for(int i=1;i<=n;i++){
			t.clear();
			for(int j=i;j<=n;j++) s[j]=0;
			for(int j=i;j<=n;j++){
				if(t[a[j]]){
					s[t[a[j]]]++;
					s[j]--; 
				}
				t[a[j]]=j;
			}
			for(int j=i+1;j<=n;j++) s[j]+=s[j-1];
			cout<<i;
			for(int j=i;j<=n;j++) if(!s[j]) ans[a[j]]++,cout<<" "<<j;
			cout<<"\n";
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

