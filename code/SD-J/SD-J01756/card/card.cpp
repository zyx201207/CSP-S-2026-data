#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn];
const int N=3e5+5;
int t[N];
int now[maxn],len;
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				now[++len]=a[j];
				t[a[j]]=len;
			}
			else{
				if(t[a[j]]<=len&&now[t[a[j]]]==a[j]){
					len=t[a[j]];
				}
				else{
					now[++len]=a[j];
					t[a[j]]=len;
				}
			}
		}
		for(int j=1;j<=len;j++){
			cnt[now[j]]++;
			//cout<<now[j]<<" ";
		}
		//cout<<'\n';
		for(int j=1;j<=m;j++){
			t[j]=0;
		}
		len=0;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
