#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool k[500005];
int cnt[500005],d[500005],col;
int t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		t[a[i]]++;
		k[i]=1;
	}
	for(int i=1;i<=n;i++){
		++col;
		for(int j=1;j<=n;j++){
			if(!k[i]) continue;
			if(cnt[a[j]]==1){
				for(int g=j+1;g<=n;g++){
					swap(a[g-1],a[g]);
				}
			}else{
				cnt[a[j]]=0;
				for(int g=1;g<=n;g++){
					if(a[g]==a[j]){
						k[i]=0;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(t[a[j]]!=col){
				cnt[a[j]]++;
				t[a[j]]=col;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << cnt[i] << " ";
	}
}

